#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long
//#define double long double

#define y0 y___0
#define y1 y___1

#define fi first
#define se second
#define pb push_back

#define timer (clock()*1.0/CLOCKS_PER_SEC)
#define e 0.000000000000000001

using namespace std;
int a[100500];
main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n,k,x;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>x, a[x]++;
    int ans=0;
    for (int i=1; i<=k; i++)
        ans+=(a[i]-(a[i]%2));
    cout<<ans+((n+1)/2 - ans/2)<<"\n";


}