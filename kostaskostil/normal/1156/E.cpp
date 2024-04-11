#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 2e5+100;
int p[nmax];
int q[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>p[i], q[p[i]]=i;

    int ans = 0;
    set<int> borders = { 0, n+1 };
    for (int i=n; i>=1; i--)
    {
        int v = q[i];
        int l = *prev(borders.lower_bound(v));
        int r = *(borders.lower_bound(v));

        if (v - l < r - v)
        for (int j=l+1; j<v; j++)
        {
            int s = i - p[j];
            if (q[s]>v and q[s]<r)
                ans++;
        }
        else
        for (int j=v+1; j<r; j++)
        {
            int s = i - p[j];
            if (q[s]>l and q[s]<v)
                ans++;
        }
        borders.insert(v);
    }
    cout<<ans<<"\n";
}