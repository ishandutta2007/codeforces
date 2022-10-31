#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()

void solve(){
    int n;
    cin>>n;
    int F = 0;
    for(int i = 1;i<=n;++i){
        int val;
        cin>>val;
        int flag = 0;
        for(int j = 2;j-1<=i;++j){
            if (val%j){
                flag = 1;
                break;
            }
        }
        if (!flag){
            F = 1;
        }
    }
    cout<<(F==0?"YES\n":"NO\n");
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}