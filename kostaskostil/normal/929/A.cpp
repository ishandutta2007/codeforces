#include <bits/stdc++.h>

using namespace std;


int main()
{
    int x[2000];
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>x[i];
    for (int i=2; i<=n; i++)
    {
        if ((x[i]-x[i-1])>k)
        {
            cout<<"-1";
            return 0;
        }
    }
    int p=x[1];
    x[n+1]=1000000000;
    int ans=0;
    for (int i=1; i<=n+1; i++)
    {
        if (x[i]>(p+k))
        {
            ans++;
            p=x[i-1];
        }
    }
    cout<<ans<<"\n";
    return 0;
}