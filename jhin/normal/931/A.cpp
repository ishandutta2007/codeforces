// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;

ll x,y,cnt1,cnt2,k,n,m,t,d,offtime,ontime;double sum;
int ho,se,mi,z;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
}

int getsum(int x)
{ int su=0;
    for(int i=0;i<x;i++)
     sum+=i+1;
    return sum;
}
int main()
{
ios_base::sync_with_stdio(false);

   cin>>x>>y;
   n=abs(x-y);
   m=2*getsum(n/2);
   if(n%2)m+=n/2+1;
   cout<<m;



    return 0;
}