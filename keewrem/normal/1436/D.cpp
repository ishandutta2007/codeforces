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
const int MAXN = 200010;
ll N,a,b;
vi adj[MAXN];
ll dp[MAXN];
ll kek[MAXN];
ll s[MAXN];
ll f[MAXN];
void dfs(int node){
    s[node]=kek[node];
    ll m = 0;
    for(auto x: adj[node]){
        dfs(x);
        s[node]+=s[x];
        f[node]+=f[x];
        m = max(dp[x],m);
    }
    if(adj[node].empty())f[node]++;
    dp[node] = max(m,(s[node]+f[node]-1)/f[node]);
//    cout << node << " "<< dp[node]<<"\n";
}
int main(){
    cin >> N;
    for(int i = 2; i <= N; i++){
        cin >> a;
        adj[a].pb(i);
    }
    for(int i = 1; i <= N; i++){
        cin >> kek[i];
    }
    dfs(1);
    cout << dp[1]<<"\n";
    return 0;
}