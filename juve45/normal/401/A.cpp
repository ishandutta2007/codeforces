#include <bits/stdc++.h>

using namespace std;

int x, n, a, s, ans;

int main()
{

    cin>>n>>x;

    for(int i=1;i<=n;i++)
    {
        cin>>a;
        s+=a;
    }
    s=abs(s);
    if(s%x!=0)
        ans=1;
    ans+=s/x;
    cout<<ans<<'\n';

    return 0;
}