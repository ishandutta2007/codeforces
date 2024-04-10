#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define MOD 1000000007LL
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    int times[n+5][k+5];
    memset(times,0,sizeof times);
    for(int i=0;i<n;i++)times[i][0]=1;
    //memset(times,1,sizeof times);
    for(int i=1;i<=k;i++){
        //memset(add,0,sizeof add);
        for(int j=0;j<n;j++){
            if(j>0)times[j][i]+=times[j-1][i-1]%MOD;
            if(j<n-1)times[j][i]+=times[j+1][i-1]%MOD;
            times[j][i]%+MOD;
        }
    }
    for(int i=0;i<n;i++){
        //memset(add,0,sizeof add);
        times[i][k+1]=times[i][k];
        for(int j=0;j<k;j++){
            if(i>0)times[i][k+1]+=times[i][j]*times[i-1][k-j-1]%MOD;
            if(i<n-1)times[i][k+1]+=times[i][j]*times[i+1][k-j-1]%MOD;
            times[i][k+1]%=MOD;
        }
    }
    //for(int i=0;i<n;i++)cout<<times[i][k+1]<<endl;
    //return 0;
    int arr[n+5];
    int ans=0;
    int t,tt;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans+=arr[i]*times[i][k+1]%MOD;
    }
    while(q--){
        cin>>t>>tt;
        t--;
        int chg=(tt-arr[t])*times[t][k+1];
        chg-=(chg/MOD)*MOD;
        if(chg<0)chg+=MOD;
        ans+=chg;
        ans+=MOD*2;
        ans%=MOD;
        arr[t]=tt;
        cout<<ans<<"\n";
    }
    return 0;
}