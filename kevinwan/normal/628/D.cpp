#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll num[2001][2001];
ll p[2001];
int n,m,d;
ll solve(string s){
    ll ans=0,acc=0;
    for(int i=n-1;i>=0;i--){
        if((n-i)&1){
            for(int j=0;j<s[i];j++)if(j!=d){
                ans+=num[i][((-acc-p[i]*j)%m+m)%m],ans%=mod;
            }
            if(s[i]==d)return ans;
            acc+=p[i]*s[i],acc%=mod;
        }
        else{
            if(s[i]<d)return ans;
            if(s[i]>d)return (ans+num[i][((-acc-p[i]*d)%m+m)%m])%mod;
            acc+=p[i]*s[i],acc%=mod;
        }
    }
    return ans;
}
int main(){
    scanf("%d%d",&m,&d);
    p[0]=1;
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    n=a.size();
    for(int i=1;i<n;i++)p[i]=p[i-1]*10%m;
    for(int i=0;i<a.size();i++)a[i]-='0',b[i]-='0';
    b[0]++;
    for(int i=0;i<n;i++)if(a[i]>9)a[i]-=10,a[i+1]++;
    num[0][0]=1;
    for(int i=1;i<=n;i++){
        if((n-i)&1^1){
            for(int j=0;j<m;j++)for(int k=0;k<10;k++)if(k!=d)num[i][(j+k*p[i-1])%m]+=num[i-1][j],num[i][(j+k*p[i-1])%m]%=mod;
        }
        else{
            for(int j=0;j<m;j++)num[i][(j+d*p[i-1])%m]+=num[i-1][j],num[i][(j+d*p[i-1])%m]%=mod;
        }
    }
    printf("%lld",(solve(b)-solve(a)+mod*2)%mod);
}