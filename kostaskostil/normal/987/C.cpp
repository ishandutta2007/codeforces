#include <bits/stdc++.h>
using namespace std;

#define int long long
int pow(int x, int y)
{
    int ans=1;
    for (int i=1; i<=y; i++)
        ans*=x;
    return ans;
}

int s[5000];
int c[5000];
int mx[5000];
int mx2[5000];
int n;
main()
{

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>s[i];
    for (int i=1; i<=n; i++)
        cin>>c[i],mx[i]=1000000000000000,mx2[i]=1000000000000000;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            if (s[i]<s[j])
                mx[j]=min(mx[j],c[i]+c[j]);
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            if (s[i]<s[j])
                mx2[j]=min(mx2[j],mx[i]+c[j]);
    int ans=1000000000000000;
     for (int i=1; i<=n; i++)
        ans=min(ans,mx2[i]);
     if (ans>100000000000)
        cout<<"-1\n";
     else
        cout<<ans<<"\n";
    return 0;
}