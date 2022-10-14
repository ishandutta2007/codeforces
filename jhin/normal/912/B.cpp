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
ll rev(ll x)
{    ll num=0;
    for(ll i=1;x>0;i<<=1,x>>=1)
        if((x&1)==0)num+=i;
    return num;
}


int main()
{
ios_base::sync_with_stdio(false);

   cin>>n>>m;
   if(m==1)cout<<n;
   else
   cout<<n+rev(n);



    return 0;
}