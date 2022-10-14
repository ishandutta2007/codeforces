// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;
string s,s2;
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
ll a[100001];

map <ll,int> bo;
int main()
{
ios_base::sync_with_stdio(false);

    cin>>m>>n;
    for(int i=1;i<=n;i++){cin>>a[i];bo[m%a[i]]=i;}
    auto it=bo.begin();x=it->second;
    cout<<x<<" "<<m/a[x];

    return 0;
}