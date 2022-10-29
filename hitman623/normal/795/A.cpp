#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int main()
{
    long long n,c1,c2,i,a=0,ans=1e18,an;
    string s;
    cin>>n>>c1>>c2;
    cin>>s;
    for(i=0;i<n;++i)
    if(s[i]=='1') a++;
    for(i=1;i<=a;++i)
    {
        an=(i-n%i)*(c1+c2*(n/i-1)*(n/i-1));
        an+=(n%i)*(c1+c2*(n/i)*(n/i));
        ans=min(ans,an);
    }
    cout<<ans;
    return 0;
}