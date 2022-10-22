#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll n,k,ans,c[5009][5009];
string s;
ll go(ll l,ll r)
{
    ll u=0;
    for(int i=l;i<=r;i++)if(s[i]=='0')u++;
   // cout<<l<<" "<<r<<" "<<" "<<(c[r-l+1][u]+mod-1)%mod<<endl;
    return (c[r-l+1][u]+mod-1)%mod;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    c[1][0]=c[1][1]=1;
    for(int i=2;i<=5005;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    cin>>n>>k;
    ans=1;
    ll r=-1;
    cin>>s;
    if(k==0){cout<<1;return 0;}
    for(int i=0;i<n;i++)
    {
        int u=i,p=s[i]-'0';
        while(u+1<n && p+s[u+1]-'0'<=k){u++;p+=s[u]-'0';}
        if(p<k)break;
        ans=(ans+go(i,u))%mod;
        if(r>i)ans=(ans-go(i,r)+mod)%mod;
        r=u;
    }
    cout<<ans<<endl;
    return 0;
}