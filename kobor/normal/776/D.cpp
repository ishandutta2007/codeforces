//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'

const int N=1e5+5;

bool stan[N];
vi ziom[N];

struct SAT{
	// m[2*i], m[2*i+1] -> is i-th false?, is i-th true?
	std::vector<std::vector<int> > g;
	std::vector<bool> m;
	std::vector<int> s;
	int c,n;

	SAT(){}
	SAT(int xd){
		n=xd;
		g = std::vector<std::vector<int> >(2*n);
		m = std::vector<bool>(2*n);
		s = std::vector<int>(2*n);
	}

	void add_clause(int x, int xval, int y, int yval){
		x = (x<<1)+xval;
		y = (y<<1)+yval;
		g[x^1].push_back(y);
		g[y^1].push_back(x);
	}

	void add_impl(int x, int xval, int y, int yval){
		x = (x<<1)+xval;
		y = (y<<1)+yval;
		g[x].push_back(y);
		g[y^1].push_back(x^1);
	}

	void add_and(int x, int y){
		add_clause(x, 1, y, 1);
		add_clause(x, 1, y, 0);
		add_clause(x, 0, y, 1);
	}
	void add_nand(int x, int y){
		add_clause(x, 0, y, 0);
	}
	void add_or(int x, int y){
		add_clause(x, 1, y, 1);
	}
	void add_nor(int x, int y){
		add_clause(x, 1, y, 0);
		add_clause(x, 0, y, 1);
		add_clause(x, 0, y, 0);
	}
	void add_xor(int x, int y){
		add_clause(x, 0, y, 0);
		add_clause(x, 1, y, 1);
	}
	void add_xnor(int x, int y){
		add_clause(x, 1, y, 0);
		add_clause(x, 0, y, 1);
	}
	void add_true(int x){
		add_clause(x, 1, x, 1);
	}
	void add_false(int x){
		add_clause(x, 0, x, 0);
	}

	bool dfs(int x){
		if(m[x^1]) return 0;
		if(m[x]) return 1;
		m[x]=1; s[c++]=x;
		for(auto ch : g[x]) if(!dfs(ch)) return 0;
		return 1;
	}

	bool solve(){
		for(int i = 0; i < 2*n; i += 2) if(!m[i] && !m[i+1]){
			c=0;
			if(!dfs(i)){
				while(c) m[s[--c]] = 0;
				if(!dfs(i+1)) return 0;
			}
		}
		return 1;
	}

	inline bool val(int a){ return m[a*2+1]; }
};

void solve(){
	int n, m, k, a;
	cin>>n>>m;
	FOR(i, 1, n) cin>>stan[i];
	FOR(i, 1, m){
		cin>>k;
		FOR(j, 1, k) cin>>a, ziom[a].pb(i-1);
	}
	SAT rozw(m);
	FOR(i, 1, n){
		if(stan[i]) rozw.add_xnor(ziom[i][0], ziom[i][1]);
		else rozw.add_xor(ziom[i][0], ziom[i][1]);
	}
	cout<<(rozw.solve() ? "YES" : "NO")<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}