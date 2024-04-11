#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=1000500;
typedef long long ll;
#define int ll

istream& operator >> (istream& is, vector<int>& v)
{
    for (int& i:v) is>>i;
    return is;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a(6);
    int n;
    cin>>a>>n;
    vector<int> v(n);
    cin>>v;
    sort(v.begin(), v.end());
    sort(a.begin(), a.end());
    set<int> s(v.begin(), v.end());

    int ans=1e18;
    for (int vmin: v)
        for (int amin: a)
        {
            int mn = vmin - amin;
            if (mn <= 0)
                continue;
            int mx = mn;

            int mn0;

            mn0 = 1e18;
            for (int i = 0; i < 6; i++)
            {
                if (v[0] - a[i] >= mn)
                    mn0 = min(mn0, v[0] - a[i]);
            }
            mx = max(mx, mn0);

            mn0=1e18;
            for (int i = 0; i < 6; i++)
            {
                if (v.back() - a[i] >= mn)
                    mn0 = min(mn0, v.back() - a[i]);
            }
            mx = max(mx, mn0);

            for (int i = 1; i < 6; i++)
            {
                auto p = s.lower_bound(mn + a[i]);
                if (p!=s.begin())
                {
                    int val = *prev(p);
                    mn0 = 1e18;
                    for (int x : a)
                        if (val - x >= mn)
                            mn0 = min(mn0, val - x);
                    mx = max(mx, mn0);
                }
                if (p!=s.end())
                {
                    int val = *p;
                    mn0 = 1e18;
                    for (int x : a)
                        if (val - x >= mn)
                            mn0 = min(mn0, val - x);
                    mx = max(mx, mn0);
                }
            }

//            cout<<mn<<" "<<mx<<"\n";
            ans = min(ans, mx-mn);
        }
    cout<<ans<<"\n";
}