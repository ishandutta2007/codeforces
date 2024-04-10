#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
const int MOD=1000000007;
main(){
    int n;
    cin>>n;
    int ans[n+10];
    int fac[n+10];
    fac[1]=1;
    for(int i=2;i<=n;i++){fac[i]=fac[i-1]*i;fac[i]%=MOD;}
    ans[3]=2;
    ans[4]=16;
    for(int i=5;i<=n;i++){
        int t=fac[i];
        t-=fac[i-1]*2;
        t+=ans[i-1]*2;
        while(t<0)t+=MOD;
        t%=MOD;
        ans[i]=t;
    }
    cout<<ans[n]<<endl;
    return 0;
}