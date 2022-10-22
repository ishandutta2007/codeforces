#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<ll,ll> co;
ll n,k,ans;
ll p[100009];
ll pw(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2==1)
        return min((ll)100001,a*pw(a,b-1));
        ll d=pw(a,b/2);
        return min((ll)100001,d*d);

}
int main()
{
 ios::sync_with_stdio(0);
 for(int i=2;i<1000;i++)
 {
     if(p[i]!=0)continue;
     for(int j=i*i;j<100008;j+=i)p[j]=i;
 }
 for(int i=2;i<100002;i++)if(p[i]==0)p[i]=i;
 cin>>n>>k;
 ll x;
 for(int i=0;i<n;i++)
 {cin>>x;
 ll s=1,r=1;
     while(x>1)
     {
         ll qq=p[x],cc=0;
         while(x%qq==0){x/=qq;cc++;}
         cc%=k;
         s*=pw(qq,cc);
        if(r==-1)continue;
         cc=(k-cc)%k;
         r*=pw(qq,cc);
         if(r>100000)r=-1;
     }
     ans+=co[r];
     co[s]++;
 }
 cout<<ans;
    return 0;
}