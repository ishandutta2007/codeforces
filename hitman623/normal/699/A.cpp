#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,a[200005],i,an=1000000007;
    char s[200005];
    cin>>n;
    cin>>s;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n-1;++i)
    {
        if(s[i]!=s[i+1] && s[i]=='R')
            an=min(an,(a[i+1]-a[i])/2);
    }
    if(an==1000000007) an=-1;
    cout<<an;
    return 0;
}