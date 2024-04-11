#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define int long long
#define pb push_back
#define fi first
#define se second

using namespace std;

int n,m;
int a[300100];
int b[300100];

int f(int s, int q)
{

    if (q<0)
        s+=q, q=0;
    if (s<0)
        return -1e18;
    if (s>=2*((s+q)/3))
        return (s+q)/3;
    return min(s/2, q+(s%2));
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i], b[i]=b[i-1]+a[i];
    int ans=0;
    int q=0;
    int t=0;
    for (int i=n; i>=1; i--)
    {
//        cout<<ans<<" "<<q<<" "<<t<<"\n";
//        cout<<"f "<<a[i]<<" "<<b[i-1]-t<<" "<<f(a[i], b[i-1]-t)<<"\n";
        ans=max(ans, f(a[i], b[i-1]-t) + q);

        q+=a[i]/2;
        t+=a[i]/2;
        if (t>0)
            t-=a[i]%2;
    }
    cout<<ans<<"\n";
    return 0;
}