#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 40+7;
const int MAXN = 2e6+7;
int A[N],cnt[2*MAXN],M[N];
int norm(int val,int mod){
    val%=mod;
    if (val<0)
        val+=mod;
    return val;
}
void solve(){
    int n;
    cin>>n;
    int flag = 0;
    for(int i = 1;i<=n;++i) {
        cin >> A[i];
        ++cnt[MAXN+A[i]];
    }
    for(int i = 0;i<MAXN*2;++i){
        if (cnt[i]*2>=n){
            flag = 1;
        }
        cnt[i] = 0;
    }
    if (flag==1){
        cout<<"-1\n";
        return;
    }
    int ans = 1;
    for(int mod = 2;mod<MAXN;++mod){
        int mx = 0;
        for(int i = 1;i<=n;++i){
            int cur = norm(A[i],mod);
            mx = max(mx,++cnt[cur]);
            M[i] = cur;
        }
        if (mx*2>=n)
            ans = mod;

        for(int i = 1;i<=n;++i){
            cnt[M[i]] = 0;
        }
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