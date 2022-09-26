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
int b[100500];
main()
{
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    int s1=0;
    int s2=0;
    for (int i=1; i<=n; i++)
    {
        int q1=max(s1, s2+a[i]);
        int q2=max(s2, s1+b[i]);
        s1=max(s1, q1);
        s2=max(s2, q2);
    }
    cout<<max(s1, s2);
}