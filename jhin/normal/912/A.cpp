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


int main()
{
ios_base::sync_with_stdio(false);

   cin>>n>>m;
   cin>>x>>y>>k;
   ll ye=2*x+y;
   ll bl=3*k+y;
   sum+=(ye>n) ? ye-n:0;sum+=(bl>m) ? bl-m:0 ;
   cout<<setprecision(12)<<sum;


    return 0;
}