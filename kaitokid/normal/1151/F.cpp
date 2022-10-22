#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll n,u,v,z,k;
struct matrix
{
    ll a[103][102];
    matrix()
    {

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)a[i][j]=0;
    }
    matrix operator * (matrix& u)
    {
        matrix prod=matrix();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
        {prod.a[i][k]+=a[i][j]*u.a[j][k];prod.a[i][k]%=mod;}
        return prod;
    }
};
ll bip(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2)return (x*bip(x,y-1))%mod;
    ll g=bip(x,y/2);
    return (g*g)%mod;
}
ll inv(ll x)
{
    return bip(x,mod-2);
}
ll c(ll x,ll y)
{
    return (x*(x-1))/2;
}
matrix pw(matrix x,ll k)
{
    matrix res =x;

    k--;
    while(k>0)
    {
        if(k%2)res=res*x;
        x=x*x;
        k/=2;
    }
    return res;
}
int b[109];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
        if(b[i]==0)u++;
        else v++;
   for(int i=0;i<u;i++)
        if(b[i]==1)z++;
   matrix single;
   ll d=c(n,2);
   ll vrs=inv(d);
   for(ll i=0;i<=n;i++)
   {
   ll p=d;
   p-=(single.a[i][i+1]=(u-i)*(v-i));
   p-=(single.a[i][i-1]=i*i);
   single.a[i][i]=((p%mod)*vrs)%mod;
   single.a[i][i+1]=((single.a[i][i+1]%mod)*vrs)%mod;
   single.a[i][i-1]=((single.a[i][i-1]%mod)*vrs)%mod;

   }
   matrix tot=pw(single,k);
   cout<<tot.a[z][0]<<endl;
return 0;
}