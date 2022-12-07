#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
// [0,L) , N-1 is virtual , 1 is rt , init!!

struct AC {
	const static int N = 201010 , M = 26;
	int ne[N][M] , fail[N] , fa[N] , rt , L, to[N];
	int newnode(){ fill_n(ne[L],M,0); return L++; }
	void ini(){ fill_n(ne[fail[0] = N-1],M,0);L = 0;rt = newnode();}
	void add(char *s, int id){
		int p = rt;
		for(int i=0;s[i];++i){
			int c = s[i] - 'a';// modify
			if(!ne[p][c]) ne[p][c] = newnode() , fa[L-1] = p;
			p = ne[p][c];
		}
		to[id] = p;
	}
	void Build(){
		vi v;v.pb(rt);
		rep(i,0,sz(v)){
			int c = v[i];
			rep(i,0,M) ne[c][i] ?
				v.pb(ne[c][i]) , fail[ne[c][i]] = ne[fail[c]][i] :
				ne[c][i] = ne[fail[c]][i];
		}
	}
} gao;

const int N = 200005;
int n, q;
char s[N];
vi g[N];
int L[N], R[N], idx;
string str[N];

void dfs(int u) {
	L[u] = ++idx;
	for (int i = 0; i < g[u].size(); i++)
		dfs(g[u][i]);
	R[u] = idx;
}

#define lowbit(x) (x&(-x))
int bit[N];

void add(int x, int w) {
	while (x <= gao.L) {
		bit[x] += w;
		x += lowbit(x);
	}
}

int get(int x) {
	int ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}

struct Q {
	int v, f, id;
	Q() {}
	Q(int v, int f, int id) : v(v), f(f), id(id) {}
};

int ans[N * 5];
vector<Q> qu[N];

int main() {
	scanf("%d%d", &n, &q);
	gao.ini();
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		str[i] = s;
		gao.add(s, i);
	}
	gao.Build(); 
	for (int i = 1; i < gao.L; i++) g[gao.fail[i]].pb(i);
	dfs(0);
	for (int i = 0; i < q; i++) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		qu[l - 1].pb(Q(k, -1, i));
		qu[r].pb(Q(k, 1, i));
	}
	for (int i = 1; i <= n; i++) {
		int u = 0;
		for (int j = 0; j < str[i].length(); j++) {
			int c = str[i][j] - 'a';
			u = gao.ne[u][c];
			add(L[u], 1);
		}
		for (int j = 0; j < qu[i].size(); j++) {
			Q x = qu[i][j];
			ans[x.id] += x.f * get(L[gao.to[x.v]], R[gao.to[x.v]]);
		}
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
	return 0;
}