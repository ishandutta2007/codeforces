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

int bpow(int a, int b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
    int x=bpow(a, b/2);
    int y=bpow(a, b%2);
    x*=x;
    x%=998244353;
    x*=y;
    x%=998244353;
    return x;
}

int dp[510][510];
int a[510];

int f(int l, int r)
{
    if (l>r)
        return 1;
    if (dp[l][r]!=-1)
        return dp[l][r];
    int q=l;
    for (int i=l+1; i<=r; i++)
        if (a[i]<a[q])
            q=i;
    int ans1=0;
    for (int i=l; i<=q; i++)
        ans1+=f(l, i-1)*f(i, q-1),ans1%=998244353;
    int ans2=0;
    for (int i=q; i<=r; i++)
        ans2+=f(i+1, r)*f(q+1, i),ans2%=998244353;
    return dp[l][r]=(ans1*ans2)%998244353;
}

main()
{

        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);


    int n;
    memset(dp, 255, sizeof(dp));
    cin>>n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    cout<<f(1, n);
//    for (int i=1; i<=n; i++)
//        for (int j=i; j<=n; j++)
//            cout<<i<<" "<<j<<" "<<f(i, j)<<"\n";
    return 0;
}