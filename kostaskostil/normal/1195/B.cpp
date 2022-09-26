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
    int n, k;
    int ans=0;
    cin>>n>>k;
    int i=0;
    while (true)
    {
        if (n-i == ans-k)
            cout<<n-i<<"\n", exit(0);
        i++;
        ans+=i;
    }
}