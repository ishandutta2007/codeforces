#include <bits/stdc++.h>

using namespace std;

//#define int int64_t

const int INF = 1e18;

const int MAXN = 2 * 1e5 + 1;

int n, a[MAXN];
vector<vector<int> > ans(MAXN);
int last[MAXN];

int32_t main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(last, 0, sizeof(last));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (last[0] < a[i])
        {
            ans[0].push_back(a[i]);
            k += (k == 0);
            last[0] = a[i];
            continue;
        }
        int l = 0;
        int r = k;
        while (r - l > 1)
        {
            int h = (l + r) >> 1;
            if (last[h] < a[i])
                r = h;
            else
                l = h;
        }
        if (r == k)
        {
            ans[k].push_back(a[i]);
            last[k] = a[i];
            k++;
            continue;
        }
        ans[r].push_back(a[i]);
        last[r] = a[i];
    }
    for (int i = 0; i < k; i++)
    {
        for (int x : ans[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}