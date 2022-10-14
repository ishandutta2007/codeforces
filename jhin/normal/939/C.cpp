// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;

ll x,y,sum,cnt1,cnt2,k,n,m;
int ho,se,mi,z,s,f;
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
ll a[200001];

int mxsum,st;
int main()
{
ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>s>>f;x=f-s;
    for(int i=n;i<n+x-1;i++)a[i]=a[i-n];
    for(int i=0;i<x;i++)sum+=a[i];
    mxsum=sum;st=s;
    for(int i=x;i<n+x;i++)
    {
        sum+=a[i]-a[i-x];s--;
        if(s==0)s=n;
        if(sum>mxsum)mxsum=sum,st=s;
        else if(sum==mxsum)st=min(st,s);
    }
    cout<<st;
    return 0;
}