#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

//typedef long long ll;
//#define int ll

const int nmax = 1000500;
int ans[nmax];
int a[nmax];
int b[nmax];
int n, k;
vector<pair<int, int> > toch;

pair<int, int> check(int pref)
{
    map<int, int> mp;
    for (int i = 1; i<=n; i++)
    {
        int x = b[i];
        for (int j=0; j<=pref; j++)
            if ((x>>j)&1)
                x-=(1<<j);
        if (mp.count(x))
            return {i, mp[x]};
        mp[x] = i;
    }
    return {-1, -1};
}

void best(int mask)
{
    for (int i=1; i<=n; i++)
        b[i] = a[i]^mask;

    pair<int, int> last = {1, 2};
    for (int j=k-1; j>=0; j--)
    {
        auto pa = check(j);
        if (pa.fi == -1)
            break;
        last = pa;
    }
    toch.pb(last);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int m = (1<<k);
    for (int i=0; i<m; i++)
        ans[i] = 1e9;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    for (int l = 0; l < k; l++)
        for (int r = l; r < k; r++)
    {
        int xmask = 0;

        for (int i = l; i<=r; i++)
            xmask^=(1<<i);
        best(xmask);
    }

    int ind = 0;
    while (clock()*1.0/CLOCKS_PER_SEC < 2.5)
    {
        int i, j;
        if (ind < toch.size())
        {
            i = toch[ind].fi;
            j = toch[ind].se;
            ind++;
        }
        else
        {
//            break;
            i = rand()%n + 1;
            j = rand()%n + 1;
        }
        if (i!=j)
        {
            for (int x=0; x<m; x++)
                ans[x] = min(ans[x], abs( (x^a[i]) - (x^a[j])) );
        }
    }

    for (int i=0; i<m; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}