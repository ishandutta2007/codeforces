// Hydro submission #62c6d255c3a9fda5622b1b22@1657197142366
#include <bits/stdc++.h>
#define int long long
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 1;
typedef pair<int, int> PII;
typedef long long ll;
vector<int> v[N];
const int mod = 1e9 + 7;
int n, m;
int a[N];
PII b[N];
bool st[N];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void solve()
{
    cin >> n >> m;
    memset(st, 0, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i].first = a[i] + i;
        b[i].second = i;
    }
    if (m >= n)
    {
        cout << 0 << endl;
        return;
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n - m; i++)
    {
        st[b[i].second] = true;
    }
    int ans = 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (st[i])
        {
            ans += res + a[i];
        }
        else
        {
            res++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}