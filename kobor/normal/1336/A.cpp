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

const int N=2e5+5;

int n, k;
vi G[N];
int rozm[N], dpth[N], dp[N];

void dfs(int v, int p){
    rozm[v]=1;
    dpth[v]=dpth[p]+1;
    for(auto &x: G[v]){
        if(x==p) continue;
        dfs(x, v);
        rozm[v]+=rozm[x];
    }
    dp[v]=dpth[v]-rozm[v]+1;
}

void solve(){
    int a, b;
    ll ans=0;
    cin>>n>>k;
    FOR(i, 2, n){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dpth[1]=-1;
    dfs(1, 1);
    sort(dp+1, dp+n+1);
    FORD(i, n, n-k+1) ans+=dp[i];
    cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    // int tt; cin>>tt;
    // FOR(te, 1, tt)
	solve();
	return 0;
}