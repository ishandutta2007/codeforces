//Krzysztof Boryczka
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

const int M=1<<18;
const int N=2e5+5;

vi G[N];
ll tree[2*M+5][2];
int pom[N], pre[N], endpre[N], h[N];
int n, num;

void dfs(int v, int p){
	pre[v]=++num;
	h[v]=h[p]+1;
	for(auto &x: G[v]) if(x!=p) dfs(x, v);
	endpre[v]=num;
}

ll query(int l, int kt){
	ll ret=0;
	l+=M-1;
	while(l){
		ret+=tree[l][kt];
		l>>=1;
	}
	return ret;
}

void add(int l, int r, int val, int kt){
	l+=M-1; r+=M-1;
	while(l<=r){
		if(l&1) tree[l++][kt]+=val;
		if((r&1)^1) tree[r--][kt]+=val;
		l>>=1; r>>=1;
	}
}

void solve(){
	int q, a, b;
	cin>>n>>q;
	FOR(i, 1, n) cin>>pom[i];
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1, 1);
	FOR(i, 1, q){
		cin>>a>>b;
		if(a==1){
			cin>>a;
			add(pre[b], endpre[b], a, h[b]&1);
			add(pre[b], endpre[b], -a, (h[b]&1)^1);
		}
		else{
			cout<<query(pre[b], h[b]&1)+pom[b]<<ent;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}