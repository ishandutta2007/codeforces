#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll d=1;
ll pw(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2==1)return a*pw(a,b-1);
    ll p=pw(a,b/2);
    return p*p;
}
int main()
{
    int t;

    cin>>t;
    while(d<(1e18))d*=3;
    while(t--)
    {ll n;
        cin>>n;

    for(int i=48;i>=0;i--)
    {
     ll s=pw(3,i);
     if((n/s)%3==2){n/=s;n++;n*=s;break;}

    }
    ll d=1,e=n;
    while(e>0)
    {
        if(e%3==2){e+=1;n+=d;}
        e/=3;
        d*=3;
    }
    cout<<n<<endl;
    }
    return 0;
}