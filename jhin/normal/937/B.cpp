// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;

ll x,y,sum,cnt1,cnt2,k,n,m;
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

    cin>>n>>m;if(m%2==0)m--;

while(m>n)
{  int j;
   for( j=3;j<=n&&j*j<=m;j+=2) if(m%j==0)break;
   if(j>n||j*j>m)return cout<<m,0;m-=2;
}

cout<<-1;
    return 0;
}