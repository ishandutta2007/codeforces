//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 2e5+7;
int dp[2][N];
void solve(){
    int n,m;
    cin>>n>>m;
    int flag = 0;
    if (n>m)
        swap(n,m),flag = 1;
    int q;
    cin>>q;
    set<pair<int,int> > S;
    for(int i = 1;i<=q;++i){
        int x,y;
        cin>>x>>y;
        if (flag)
            swap(x,y);
        S.insert({x,y});
    }
    int t = 0;
    dp[t][1] = 1;
    for(int step = 1;step<=1e10;++step){
        if (dp[t][n]==m){
            cout<<step-1<<'\n';
            return;
        }
        for(int w = 1;w<=n;++w){
            if (dp[t][w]==0)
                continue;
            int s = w+dp[t][w]+S.count({w,dp[t][w]});
            dp[t^1][min(n,s)] = max(dp[t^1][min(n,s)],dp[t][w]);
            dp[t^1][w] = max(dp[t^1][w],min(m,s));
        }
        for(int w = 1;w<=n;++w){
            dp[t][w] = 0;
        }
        t^=1;
    }

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}