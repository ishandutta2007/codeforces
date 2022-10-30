#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int N = 3e5+7;
int cnt[N];
int can[N],c[N];
vector<int> G[N];
void calc(int v,int par){
    cnt[v] = c[v];

    int flag = c[v];
    for(int to:G[v]){
        if (to==par)
            continue;
        calc(to,v);
        can[v] +=  can[to];
        cnt[v]+=cnt[to];
        flag = max(flag,c[to]);
    }
    can[v] += cnt[v]>1 && flag>0;
}
bool ans[N];
void dfs(int v,int par){
    cnt[v] = c[v];
    can[v] = 0;
    int flag = c[v];
    for(int to:G[v]){
        can[v] += can[to];
        cnt[v]+=cnt[to];
        flag += c[to];
    }

    ans[v] = max(flag>0,can[v]>0);
    for(int to:G[v]){
        if (to==par)
            continue;
        int pcan = can[v],pcnt = cnt[v],pflag = flag;
        cnt[v]-=cnt[to];
        flag-=c[to];
        can[v]-=can[to];
        can[v] += (cnt[v]>1 && flag>0);
        dfs(to,v);
        can[v] = pcan;
        cnt[v] = pcnt;
        flag = pflag;
    }
}
void solve() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>c[i];
    for(int i = 1;i<n;++i){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    calc(1,1);
    dfs(1,1);
    for(int i = 1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
}

signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}