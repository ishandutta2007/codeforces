#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

struct fenw{
    vector<int> a;
    fenw(int _n)
    {
        a.resize(_n);
    }
    int get(int x)
    {
        if (x < 0) return -1e9;
        int res = 0;
        while (x >= 0)
        {
            res = max(res, a[x]);
            x = (x & (x + 1)) - 1;
        }
        return res;
    }
    void set(int x, int val)
    {
        while (x < a.size())
        {
            a[x] = max(a[x], val);
            x |= (x + 1);
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    vector<pair<int, int> > st = {{n, -1}};
    vector<int> high(n);
    for (int i = 0; i < n; i++)
    {
        while (a[i] >= st.back().first)
            st.pop_back();
        high[i] = st.back().second;
        st.push_back({a[i], i});
    }
    vector<pair<int, int> > s;
    for (int i = 0; i < n; i++)
        s.push_back({a[i], i});
    sort(s.begin(), s.end());
    fenw V(n);
    int ans = 1;
    for (auto e : s)
    {
        int i = e.second;
        int dp = max(V.get(i) + 1, V.get(high[i]) + 2);
        ans = max(ans, dp);
        V.set(i, dp);
        //cout << i << " " << dp << "\n";
    }
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}