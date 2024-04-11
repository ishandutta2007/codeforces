#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 1e6+100;

int ans;
int a[nmax];
int s[nmax];

void spl(int l, int r)
{
    if (l==r)
        return;
    if (l+1==r)
    {
        if (a[l]!=1)
            ans=max(ans, 1ll);
        return;
    }
    int m = (l+r)/2;
    spl(l, m);
    spl(m, r);
    s[m] = a[m];
    for (int i = m+1; i<r; i++)
        s[i] = __gcd(a[i], s[i-1]);
    s[m-1] = a[m-1];
    for (int i = m-2; i>=l; i--)
        s[i] = __gcd(a[i], s[i+1]);

    for (int i=m-1; i>=l; i--)
    {
        int g = s[i];
        if (s[i] == 1)
            continue;
        int l0 = m-1;
        int r0 = r;
        while (r0 - l0 > 1)
        {
            int m0 = (l0+r0)/2;
            if (__gcd(g, s[m0]) == 1)
                r0 = m0;
            else
                l0 = m0;
        }
        ans=max(ans, l0 - i + 1);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while (___--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i : v)
            cin>>i;
        n--;
        vector<int> d(n);
        for (int i=0; i<n; i++)
            d[i] = abs(v[i] - v[i+1]);
        for (int i=0; i<n; i++)
            a[i] = d[i];
        ans=0;
        spl(0, n);
        cout<<ans+1<<"\n";
    }
}