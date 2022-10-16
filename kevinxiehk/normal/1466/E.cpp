#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define MOD (1000000007)
using namespace std;

void solve(){
    int n,t;cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    bool arr2[n+5][64];
    for(int i=0;i<n;i++){
        t=arr[i];
        for(int j=0;j<=61;j++){
            arr2[i][j]=t&1;
            t/=2;
        }
    }
    int cnt[65],an[65],orr[65];
    for(int i=0;i<=61;i++){
        int tcnt=0;
        for(int j=0;j<n;j++){
            tcnt+=arr2[j][i];
        }
        cnt[i]=tcnt;
        //cout<<tcnt<<endl;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=61;j++){
            if(arr2[i][j])an[j]=cnt[j];
            else an[j]=0;
            if(arr2[i][j])orr[j]=n;
            else orr[j]=cnt[j];
        }
        int ts=0;
        int t1=0,t2=0;
        for(int j=0;j<=61;j++){
            t1+=(1LL<<j)%MOD*an[j]%MOD;
            t2+=(1LL<<j)%MOD*orr[j]%MOD;
            t1%=MOD;t2%=MOD;
            //for(int k=0;k<=61;k++){
                //ts+=((((int)pow(2,j)%MOD)*((int)pow(2,k)%MOD)%MOD)*(an[j]*orr[k]%MOD))%MOD;
                //ts%=MOD;
                //cout<<ts<<endl;
            //}
        }
        ans+=(t1*t2)%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}