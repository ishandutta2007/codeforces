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
//END OF TEMPLATE

const int N=1e6+5;
const int M=1<<20;

vi akt;
int n, w, m;
ll tree[M*2+5];
deque<ii> q;

ll query(int l){
	ll ret=0; l+=M;
	while(l){
		ret+=tree[l];
		l>>=1;
	}
	return ret;
}

void add(int l, int r, int val){
	l+=M; r+=M;
	while(l<=r){
		if(l&1) tree[l++]+=val;
		if(!(r&1)) tree[r--]+=val;
		l>>=1; r>>=1;
	}
}

void dodaj(){
	FOR(i, 1, w){
		if(i==m+1 && m+1<=w-m){
			add(m+1, w-m, max(q.front().st, 0));
			i=w-m;
			continue;
		}
		while(SIZE(q) && w-i<m-q.front().nd) q.pop_front();
		if(i<=m){
			while(SIZE(q) && q.back().st<=akt[i-1]) q.pop_back();
			q.pb({akt[i-1], i});
		}
		if(i+m<=w || i>m) add(i, i, max(q.front().st, 0));
		else add(i, i, q.front().st);
	}
	q.clear();
}

void solve(){
	int a;
	cin>>n>>w;
	FOR(i, 1, n){
		cin>>m;
		FOR(j, 1, m){
			cin>>a;
			akt.pb(a);
		}
		dodaj();
		akt.clear();
	}
	FOR(i, 1, w) cout<<query(i)<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}