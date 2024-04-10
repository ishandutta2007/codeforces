
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 40+7;
const int MAXN = 2e6+7;
int A[N];
void solve(){
    int n;
    cin>>n;
    int flag = 0;
    for(int i = 1;i<=n;++i) {
        cin >> A[i];
        if (A[i] != A[1])
            flag = 1;
    }
    if (flag==0){
        cout<<"-1\n";
        return;
    }
    int ans = 1;
    for(int mod = 2;mod<MAXN;++mod){
        int frs = A[1]%mod;
        frs = (mod+frs)%mod;
        int flag = 0;
        for(int i = 1;i<=n;++i){
            int cur = A[i]%mod;
            cur = (mod+cur)%mod;
            if (cur!=frs){
                flag = 1;
                break;
            }
        }
        if (flag==0)
            ans = mod;
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();


    return 0;
}