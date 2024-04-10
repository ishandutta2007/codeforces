#include<bits/stdc++.h>

using namespace std;
#define fi first
#define se second

const int N = 1000005;
const int INF = 1e9;
const int MOD = 998244353;

long long n, m, x, k, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> k >> y;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];
    vector<int> c(n);
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (a[i] == b[j])
        {
            c[i] = 1;
            j++;
        }
    }
    if (j < m)
    {
        cout << -1;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < n; )
    {
        if (c[i] == 0)
        {
            int r = i;
            while (r + 1 < n && c[r + 1] == 0) r++;
            int len = r - i + 1;
            int maxp = 0;
            for (int j = i; j <= r; j++) maxp = max(maxp, a[j]);
            int can_kill = 0;
            if (i - 1 >= 0) if (a[i - 1] > maxp) can_kill = 1;
            if (r + 1 < n) if (a[r + 1] > maxp) can_kill = 1;
            if (can_kill == 0 && len < k)
            {
                cout << -1;
                return 0;
            }
            ans += len % k * y;
            len -= len % k;
            while (len > k)
            {
                len -= k;
                ans += min(k * y, x);
            }
            if (len)
            if (can_kill)
            {
                ans += min(k * y, x);
            }
            else
            {
                ans += x;
            }
            i = r + 1;
        }
        else i++;
    }
    cout << ans;
}