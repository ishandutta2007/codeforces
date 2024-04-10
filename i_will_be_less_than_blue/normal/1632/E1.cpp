
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=4010;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
#define endl '\n'
int d[N][N];
vector<int>g[N];
int h[N];
void dfs(int v,int pr){
    h[v]=h[pr]+1;
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
        }
    }
}
int ans[N];
vector<int>Q[N];
bool good[N];
int D=0;
int n;
void add(int v){
    good[v]=true;
    dfs(v,0);
    for (int i=1;i<=n;i++){
        if (good[i]) D=max(D,h[i]);
    }

}
void solve(){
    cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    h[0]=-1;
    dfs(1,0);
    for (int i=1;i<=n;i++) ans[i]=n;
    for (int i=1;i<=n;i++) Q[h[i]].push_back(i);
    bool was=false;
    for (int i=n;i>=1;i--){
        for (int v:Q[i]){
            add(v);
            was=true;
        }
        int pos;
        if (!was) pos=n;
        else pos=i-1-(D+1)/2;
        if (pos>0) ans[pos]=min(ans[pos],i-1);
    }


    for (int i=n-1;i>=1;i--) ans[i]=min(ans[i],ans[i+1]);

    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    for (int i=1;i<=n;i++){
        ans[i]=0;
        h[i]=0;
        Q[i].clear();
        g[i].clear();
        good[i]=false;
    }
    D=0;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
5 1 1
1 4 5 2 3
2 1 3
**/