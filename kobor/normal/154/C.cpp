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
const int mod=1e9+123;
const int pp[2]={(int)1e6+37, (int)1e6+39};

vi G[N];
vii edg;
ll ans;
int n, m;
unordered_map<ll, int> M;

ll gethasz(int v){
	int hsz[2]={0, 0};
	for(auto &x: G[v]) FOR(j, 0, 1) hsz[j]=((ll)hsz[j]*pp[j]+x)%mod;
	return ((ll)hsz[0]<<32)+hsz[1];
}

void solve(){
	int a, b;
	ll hsz;
	cin>>n>>m;
	FOR(i, 1, m){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
		edg.pb({a, b});
	}
	FOR(i, 1, n) sort(G[i].begin(), G[i].end());
	FOR(i, 1, n){
		hsz=gethasz(i);
		ans+=M[hsz]++;
	}
	FOR(i, 1, n) G[i].pb(i);
	FOR(i, 1, n) sort(G[i].begin(), G[i].end());
	M.clear();
	FOR(i, 1, n){
		hsz=gethasz(i);
		ans+=M[hsz]++;
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}