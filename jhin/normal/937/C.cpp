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

   cin>>k>>d>>t;
  n=2*t;cnt1=k/d;if(k%d!=0)cnt1++;
   ontime=k*2;offtime=(cnt1*d)-k;//cout<<cnt1<<endl;
   m=n%(ontime+offtime);n/=ontime+offtime;//cout<<"M"<<m<<endl;
   sum=n*(k+offtime);//cout<<sum<<endl;
   if(m>ontime)
   {sum+=k+m-ontime;
    //cout<<sum<<endl;
   }
   else sum+=double(m)/double(2);
   cout<<setprecision(18)<<sum;


    return 0;
}