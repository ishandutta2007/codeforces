#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd(time(NULL));
const int N=300100;
const int L=60;
const ll inf=1e18;
int n,k;
ll s[N];
vector<int>g[N];
map<int,ll>dp[N];
void dfs0(int v){
    for (int to:g[v]){
        s[to]+=s[v];
        dfs0(to);
    }
}
ll dfs(int v,int k){
    if (dp[v].count(k)) return dp[v][k];
    if (g[v].empty()) return s[v]*k;
    ll res=0ll;
    vector<ll>best;
    int rem=k%g[v].size();
    for (int to:g[v]){
        ll a=dfs(to,(k-rem)/g[v].size());
        if (rem){
            ll b=dfs(to,(k-rem)/g[v].size()+1);
            best.push_back(b-a);
        }
        res+=a;
    }
    sort(best.begin(),best.end());
    reverse(best.begin(),best.end());
    for (int i=0;i<rem;i++) res+=best[i];
    return dp[v][k]=res;
}
void solve(){
    cin>>n>>k;
    for (int i=2;i<=n;i++){
        int p;cin>>p;
        g[p].push_back(i);
    }
    for (int i=1;i<=n;i++) cin>>s[i];
    dfs0(1);
    cout<<dfs(1,k)<<'\n';
    for (int i=1;i<=n;i++) {
        dp[i].clear();
        g[i].clear();
    }





}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
10 8
1234 2 3 3 2 1 1 2 3 4
2 1 6 2
1 1 1
2 1 6 2
2 1 9 2
1 10 5
2 1 9 3
1 3 5
2 3 10 2

**/