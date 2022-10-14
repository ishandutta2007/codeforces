#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define int ll
int T,a,b;
ll N,M; const ll MOD = 1000000007;
const int MAXN = 100002;
bool vis[MAXN];
vi adj[MAXN];
vll kek;
ll dfs(int node){
    vis[node] = 1;
    ll k = 1;
    for(auto x: adj[node]){
        if(vis[x])continue;
        k+=dfs(x);
    }
    if(node!=1)kek.pb((k*(N-k)));
    return k;
}
signed main(){
    cin >> T;
    while(T--){
        cin >> N;
        kek.clear();
        for(int i = 0; i <= N; i++){adj[i].clear(); vis[i] = 0;}
        for(int i = 1; i < N; i++){
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        cin >> M;
        vll p(M);
        for(auto &x: p)cin >> x;
        while(p.size()<N-1)p.pb(1LL);
        sort(p.begin(),p.end());
        dfs(1);
        for(int i = N-1; i < p.size(); i++)p[N-2]=(p[N-2]*p[i])%MOD;
        sort(kek.begin(),kek.end());
        ll ans = 0;
        for(int i = 0; i < N-1; i++){
            ans = (ans + p[i]*(kek[i]%MOD))%MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}