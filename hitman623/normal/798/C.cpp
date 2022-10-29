#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long gcd(long a, long b)
{
    if(a==0) return b;
    else return gcd(b%a,a);
}
int main()
{
    long n,i,a[100005],o=0,g=0,ans=0;
    cin>>n;
    for(i=0;i<n;++i)
    {cin>>a[i];
    g=gcd(g,a[i]);}
    if(g>1) {cout<<"YES"<<endl<<0;exit(0);}
    for(i=0;i<n;i++)
    {
        if(a[i]%2==1)
            o++;
        else
        {ans+=o/2+2*(!!(o%2));
        o=0;}
    }
    ans+=o/2+2*(!!(o%2));
    cout<<"YES"<<endl;
    cout<<ans;
    return 0;
}