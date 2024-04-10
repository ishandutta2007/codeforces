//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'a'+1)
const int MAXN = 10007;
vector<int> V[MAXN];
int mi[MAXN],vis[MAXN];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<MAXN;++i)
        mi[i] = MAXN,V[i].push_back(0);
    vis[0] = 1;
    for(int i = 1;i<=n;++i){
        int cur;
        cin>>cur;
        int sz = V[cur].size();
        for(int pos = 0;pos<sz;++pos){
            int ne = V[cur][pos]^cur;
            vis[ne] = 1;
            for(int j = mi[ne]-1;j>cur;--j)
                V[j].push_back(ne);
            mi[ne] = min(mi[ne],cur+1);
        }
        V[cur].clear();
    }
    int res = 0;
    for(int i = 0;i<MAXN;++i)
        res+=vis[i];
    cout<<res<<endl;
    for(int i = 0;i<MAXN;++i)
        if (vis[i])
            cout<<i<<' ';
    cout<<endl;
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();

    return 0;
}