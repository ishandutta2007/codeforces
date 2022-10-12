#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct RotatedSegment{
    ll l, r;
    int t;
    RotatedSegment()
    {
        l = 0, r = 0;
        t = 0;
    }
    void rotate(ll x)
    {
        swap(l, r);
        l = x - l;
        r = x - r;
        l = max(1ll, l);
        if (l > r) t = 0;
    }
    int find(ll x)
    {
        if (!t) return 0;
        return l <= x && x <= r;
    }
};

struct RotatedSet{
    set<ll> s;
    ll root;
    ll dir;
    RotatedSegment segm;

    RotatedSet()
    {
        root = 0;
        dir = 1;
    }
    void clear()
    {
        segm.t = 0;
        root = 0;
        dir = 1;
        s.clear();
    }
    void use_segment(ll l, ll r)
    {
        segm.t = 1;
        segm.l = l;
        segm.r = r;
    }
    void insert(ll x)
    {
        s.insert(root + dir * x);
    }
    int size()
    {
        if (segm.t) return 1;
        return s.size();
    }
    int find(ll x)
    {
        if (segm.find(x)) return 1;
        return s.find(root + dir * x) != s.end();
    }
    void rotate(ll y)
    {
        if (segm.t) segm.rotate(y);
        root += dir * y;
        dir *= -1;
        if (dir == -1)
        {
            auto it = s.end();
            if (it != s.begin()) it--;
            vector<ll> a;
            while (s.size())
            {
                if (*it >= root) a.push_back(*it);
                else break;
                if (it == s.begin()) break;
                it--;
            }
            for (auto e : a) s.erase(e);
        }
        else
        {
            auto it = s.begin();
            vector<ll> a;
            while (s.size())
            {
                if (*it <= root) a.push_back(*it);
                else break;
                it++;
                if (it == s.end()) break;
            }
            for (auto e : a) s.erase(e);
        }
    }
    void write()
    {
        for (auto e : s)
        {
            cout << abs(e - root) << " ";
        }
        if (segm.t)
        {
            cout << "[" << segm.l << " " << segm.r << "]";
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    RotatedSet S;
    int k = 0, two = -1;
    if (a[0] % 2 == 0)
    {
        S.insert(a[0] / 2);
    }
    for (int i = 1; i < n; i++)
    {
        if (two == -1)
        {
            if (S.size())
            {
                k = k + 1;
                if (a[i] % 2 == 0 && S.find(a[i] / 2))
                {
                    two = a[i] / 2;
                }
                S.rotate(a[i]);
                if (a[i] % 2 == 0)
                {
                    S.insert(a[i] / 2);
                }
            }
            else
            {
                int p = a[i - 1];
                if (a[i] - a[i - 1] + 1 <= a[i] - 1)
                {
                    //for (int j = a[i] - a[i - 1] + 1; j <= a[i] - 1; j++)
                    //    S.insert(j);
                    S.use_segment(a[i] - a[i - 1] + 1, a[i] - 1);
                }
                if (a[i] % 2 == 0)
                {
                    S.insert(a[i] / 2);
                }
                if (a[i] % 2 == 0 && a[i] / 2 < p)
                {
                    two = a[i] / 2;
                }
                if (a[i] <= a[i - 1])
                {
                    k++;
                    S.clear();
                    if (two != -1)
                    {
                        S.insert(two);
                        two = -1;
                    }
                }
            }
        }
        else
        {
            k = k + 2;
            S.clear();
            if (a[i] % 2 == 0) S.insert(a[i] / 2);
            if (a[i] - two > 0) S.insert(a[i] - two);
            if (a[i] % 2 == 0 && two == a[i] / 2)
            {
                two = a[i] / 2;
            }
            else
            {
                two = -1;
            }
        }
        #ifdef LOCAL
        cout << k << "\n";
        S.write(); cout << "\n";
        cout << two << "\n";
        cout << "\n";
        #endif // LOCAL
    }
    int ans = k;
    if (S.size()) ans = k + 1;
    if (two != -1) ans = k + 2;
    //cout << ans << "\n";
    cout << 2 * n - ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}