#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
//#define int ll
using namespace std;
typedef long long ll;
const int N=5010;
const ll mod=998244353;
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2)%mod;
}
int a[N];
ll dp[N][N];
bool ok[N];
ll cnt[N];
int b[N];
void solve(){
//    memset(a,0,sizeof(a));
//    memset(dp,0,sizeof(dp));
//    memset(ok,0,sizeof(ok));
//    memset(cnt,0,sizeof(cnt));
//    memset(b,0,sizeof(b));
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
//    for (int i=1;i<=n;i++) a[i]=rand()%n+1;

    sort(a+1,a+n+1);
//    cout<<n<<endl;
//    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//    cout<<endl;
//    for (int i=1;i<=n;i++) b[i]=a[i];
//    int tot=0;
//    do{
//        bool ok=true;
//        for (int i=4;i<=n;i+=2){
//            ok&=(b[i]>b[i-2]);
//        }
//        for (int i=2;i<=n;i+=2){
//            ok&=(b[i]>b[i-1]);
//        }
//        for (int i=2;i<=n-2;i+=2){
//            ok&=(b[i]>b[i+1]);
//        }
////        if (ok){
////            for (int i=1;i<=n;i++) cout<<b[i]<<" ";
////            cout<<endl;
////        }
//        tot+=ok;
//    }while (next_permutation(b+1,b+n+1));
//    cout<<"A "<<tot<<endl;
    reverse(a+1,a+n+1);
    a[n+1]=0;
    ok[n+1]=true;
    cnt[n+1]=1;
    for (int i=1;i<=n;i++){
        if (a[i]>a[i+1]) {
            ok[i]=true;
        }
        cnt[a[i]]++;
    }
    if (a[1]==a[2]){
        for (int i=0;i<=n+1;i++){
            cnt[i]=0;
            ok[i]=false;
            a[i]=b[i]=0;
            for (int j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }
        cout<<0<<endl;
        return;
    }
    dp[1][1]=1;
    for (int i=1;i<n;i++){
        for (int j=1;j<n/2;j++){
            if (ok[i+1]){
                dp[i+1][j+1]+=dp[i][j]*cnt[a[i+1]];
                dp[i+1][j+1]%=mod;
            }
            dp[i+1][j]+=dp[i][j]*(2*j-i-1);
            dp[i+1][j]%=mod;
        }
    }

    ll res=0ll;
    for (int i=n/2;i<=n;i++){
        ll mult=1ll;
        for (int j=i+1;j<=n;j++){
            mult*=(n-j+1);
            mult%=mod;
        }
        res+=mult*dp[i][n/2];
        res%=mod;
    }
    ll dv=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=cnt[i];j++){
            dv*=j;
            dv%=mod;
        }
    }
    dv=binpow(dv,mod-2);
    res*=dv;
    res%=mod;
    cout<<res<<endl;
    for (int i=0;i<=n+1;i++){
        cnt[i]=0;
        ok[i]=false;
        a[i]=b[i]=0;
        for (int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }


}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}