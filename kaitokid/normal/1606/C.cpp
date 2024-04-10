#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[12],k,p[12];
bool ch(ll x)
{
    cout<<x<<" ";
    ll u=0;
    for(int i=n-1;i>=0;i--)
    {
        u+=x/a[i];
        x=x%a[i];
    }
    cout<<u<<endl;
    return u<=k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p[0]=1;
    for(int i=1;i<=10;i++)p[i]=p[i-1]*10;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;

       for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }
    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(i==n-1||k<p[a[i+1]-a[i]]-1){res+=(k+1)*p[a[i]];k=0;break;}
        k-=p[a[i+1]-a[i]]-1;
        res+=(p[a[i+1]-a[i]]-1)*p[a[i]];
    }
    cout<<res<<endl;}
        /*ll r=0,d=1;
       for(int g=9;g>=1;g--)
       {

        while(ch(r+d*g))
        {
            r=r+d*g;
            d*=10;}


       }
       cout<<r<<endl;


    }*/
    return 0;
}