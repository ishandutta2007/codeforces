#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e6+7;
int pref[N];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > A(n+7);
    for(int i = 0;i<n+7;++i) {
        A[i].resize(m + 7, 0);
        for (int j = 0; j <= m; ++j)
            A[i][j] = 0;
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            char ch;
            cin>>ch;
            if (ch=='X')
                A[i][j] = 1;
            else if (ch=='.')
                A[i][j] = 0;
            else assert(0);
        }
    }
    for(int pos = 1;pos<=m;++pos){
        int flag = 0;
        for(int i = 1;i<=n;++i){
            if (A[i-1][pos]==1 && A[i][pos-1]==1){
                flag = 1;
            }
        }
        pref[pos] = pref[pos-1]+flag;
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if (pref[r]-pref[l])
            cout<<"NO\n";
        else cout<<"YES\n";
    }

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}