#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define bitcount(x) __builtin_popcountll(x)

const int N = 1e7 + 2;

int sieve[N];
int cnt[N];

void add(int x, int D)
{
    vector<int> d;
    int lst = -1;
    while (x > 1)
    {
        if (sieve[x] != lst) d.push_back(sieve[x]);
        lst = sieve[x];
        x /= sieve[x];
    }
    for (int mask = 0; mask < (1 << d.size()); mask++)
    {
        int x = 1;
        for (int i = 0; i < d.size(); i++)
        {
            if ((1 << i) & mask) x *= d[i];
        }
        cnt[x] += D;
    }
}

int get(int x)
{
    vector<int> d;
    int lst = -1;
    while (x > 1)
    {
        if (sieve[x] != lst) d.push_back(sieve[x]);
        lst = sieve[x];
        x /= sieve[x];
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << d.size()); mask++)
    {
        int x = 1;
        for (int i = 0; i < d.size(); i++)
        {
            if ((1 << i) & mask) x *= d[i];
        }
        if (bitcount(mask) % 2 == 1) ans += cnt[x];
        else ans -= cnt[x];
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << "\n";

    for (int i = 2; i < N; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i; j < N; j += i) sieve[j] = i;
        }
    }

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) add(a[i], 1);
    int t = -1;
    for (int i = 0; i < n; i++)
    {
        if (get(a[i]) <= n - 2)
            t = i;
    }
    if (t == -1)
    {
        for (int i = 0; i < n; i++) add(a[i], -1);
        int sz = 0;
        for (int i = 0; i < n; i++)
        {
            if (get(a[i]) == sz)
            {
                add(a[i], 1);
                cout << i + 1 << " ";
                sz++;
                if (sz == k) return 0;
            }
        }
    }
    vector<int> near;
    for (int i = 0; i < n; i++)
    {
        if (i == t) continue;
        if (near.size() < 2 && __gcd(a[i], a[t]) == 1)
            near.push_back(i);
    }
    add(a[t], -1);
    add(a[near[0]], -1);
    add(a[near[1]], -1);

    vector<int> good;
    vector<int> items;
    for (int i = 0; i < n; i++)
    {
        if (i != t && i != near[0] && i != near[1])
        {
            if (get(a[i]) == n - 3)
            {
                good.push_back(i);
            }
            else
            {
                items.push_back(i);
            }
        }
    }
    if (good.size() >= k)
    {
        for (int i = 0; i < k; i++)
        {
            cout << good[i] + 1 << " ";
        }
        return 0;
    }
    for (int i = 0; i < good.size(); i++)
    {
        add(a[good[i]], -1);
    }
    for (int i = 0; i < items.size(); i++)
    {
        add(a[items[i]], -1);
    }
    assert(cnt[1] == 0);
    if (k == 3)
    {
        cout << t + 1 << " " << near[0] + 1 << " " << near[1] + 1 << " ";
        return 0;
    }
    int L = 0, R = items.size();
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        for (int i = 0; i <= M; i++) add(a[items[i]], 1);
        int sz = 0;
        for (int i = 0; i <= M; i++) if (get(a[items[i]]) <= M) sz++;
        if (sz + 3 >= k) R = M;
        else L = M;
        for (int i = 0; i <= M; i++) add(a[items[i]], -1);
    }
    for (int i = 0; i < R; i++) add(a[items[i]], 1);
    vector<int> away;
    for (int i = 0; i < R; i++) if (get(a[items[i]]) == R && __gcd(a[items[i]], a[items[R]]) == 1) away.push_back(items[i]);
    add(a[items[R]], 1);
    set<int> ans = {t, near[0], near[1]};
    for (int i = 0; i <= R; i++) if (get(a[items[i]]) <= R) ans.insert(items[i]);

    for (int i = 0; i < (int)away.size() - 1; i++)
    {
        if (ans.size() > k)
        {
            ans.erase(away[i]);
        }
    }
    if (ans.size() > k)
    {
        ans.erase(near[1]);
    }
    for (auto e : ans) cout << e + 1 << " ";
}