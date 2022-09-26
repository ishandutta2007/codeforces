#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

bool powless(int p, int k)
{
    if (p > 60)
        return false;
    return (1ll<<p) < k;
}

void solve()
{
    int n, k;
    cin>>n>>k;

    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        int sz = 1;
        if (i==n)
        {
            if (k==1)
            {
                v.pb(i);
                break;
            }
            else
            {
                cout<<"-1\n";
                return;
            }
        }

        while ( powless(n-i-sz, k) )
        {
            k-=(1ll << (n-i-sz)), sz++;
            if (n-i-sz < 0)
            {
                if (k==0)
                {
                    sz++;
                    break;
                }
                if (k==1)
                {
                    break;
                }
                else
                {
                    cout<<"-1\n";
                    return;
                }
            }
        }

        for (int j = i+sz-1; j>=i; j--)
            v.pb(j);
        i+=sz-1;
    }
    for (int i : v)
        cout<<i<<" ";
    cout<<"\n";
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
        solve();
    }
}