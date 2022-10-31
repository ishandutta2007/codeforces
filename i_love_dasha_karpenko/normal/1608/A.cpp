#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(), var.end()
#define mp make_pair
#define gp(x,y) ((x-1)*m+y-1)
const int SZ = 1e5+7;
bool vis[SZ];
vector<int> simp;
void solve(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i)
        cout<<simp[i]<<' ';
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int sp = 2;sp<SZ;++sp){
        if (vis[sp])
            continue;
        simp.push_back(sp);
        for(ll j = ll(sp)*sp;j<SZ;j+=sp)
            vis[j] = 1;
    }
    //cout<<simp.size()<<endl;
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}