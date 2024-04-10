#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e5+7;
int vis[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        vis[i] = 0;
    for(int i = 1;i<=m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        ++vis[b];
    }
    for(int i = 1;i<=n;++i){
        if (vis[i]==0){
            for(int j = 1;j<=n;++j){
                if (j==i)
                    continue;
                cout<<i<<' '<<j<<endl;
            }
            return;
        }
    }

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}