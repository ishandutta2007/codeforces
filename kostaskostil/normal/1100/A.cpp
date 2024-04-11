#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

int s[100500];

main()
{
    int n, k;
    cin>>n>>k;
    int x;
    int t=0;
    for (int i=0; i<n; i++)
        cin>>x, s[i%k]+=x, t+=x;
    int ans=0;
    for (int i=0; i<k; i++)
        ans=max(ans, abs(t-s[i]));
    cout<<ans<<"\n";
    return 0;
}