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
int c[15];
int md= 998244353;

int cnt(int x)
{
    int q=0;
    while (x>0)
        x/=10, q++;
    return q;
}

int f(int x, int z)
{
    int ans=0;
    int t=1;
    while (x>0)
    {
        ans+=(x%10)*t;
        if (z>0)
            t*=100, z--;
        else
            t*=10;
        x/=10;
        ans%=md;
        t%=md;
    }
    return ans;
}

int g(int x, int z)
{
    int ans=0;
    int t=10;
    z--;
    while (x>0)
    {
        ans+=(x%10)*t;
        if (z>0)
            t*=100, z--;
        else
            t*=10;
        x/=10;
        ans%=md;
        t%=md;
    }
    return ans;
}

main()
{
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i], c[cnt(a[i])]++;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<15; j++)
            ans+=c[j]*(f(a[i], j) + g(a[i], j)), ans%=md;
//        ans-=(f(a[i], cnt(a[i]) + g(a[i], cnt(a[i]))));
        ans%=md;
    }
    cout<<(ans+md)%md;
}