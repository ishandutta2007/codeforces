#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n,s1,s2,b,m,k;
    cin>>n>>b;
    s1=1;
    ll a[100],f=0;

    for (ll i=0;i<n;i++)
        cin>>a[i];

    for (ll i=n-1;i>=0;i--)
    {
        f+=s1*a[i];
        s1*=b;
    }

    //cout<<f<<endl;

       ll a2[100],s=0;
       cin>>m>>k;
    for (int i=0;i<m;i++)
        cin>>a2[i];

    s2=1;
    for (ll i=m-1;i>=0;i--)
    {
        s+=s2*a2[i];
        s2*=k;
    }
   // cout<<s<<endl;

    if (f>s)
        cout<<'>';
    else if (f<s)
        cout<<'<';
    else cout<<'=';
    return 0;
}