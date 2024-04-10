#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k;

struct Set2{
    multiset<pair<ll, ll> > s1, s2;
    ll total1 = 0;
    ll cnt1 = 0;
    void push12()
    {
        total1 -= (*s1.rbegin()).first * (*s1.rbegin()).second;
        cnt1 -= (*s1.rbegin()).second;
        s2.insert(*s1.rbegin());
        auto it = s1.end();
        it--;
        s1.erase(it);
    }
    void push21()
    {
        total1 += (*s2.begin()).first * (*s2.begin()).second;
        cnt1 += (*s2.begin()).second;
        s1.insert(*s2.begin());
        auto it = s2.begin();
        s2.erase(it);
    }
    void cutoff()
    {
        while (s1.size() && cnt1 - (*s1.rbegin()).second >= k)
        {
            push12();
        }
        while (s2.size() && cnt1 < k)
        {
            push21();
        }
    }
    void balance()
    {
        while (s1.size() && s2.size() && (*s1.rbegin()).first > (*s2.begin()).first)
        {
            push12();
            push21();
        }
    }
    void insert(pair<ll, ll> a)
    {
        s2.insert(a);
        for (int i = 0; i < 7; i++)
            cutoff(), balance();
    }
    void erase(pair<ll, ll> a)
    {
        if (s1.find(a) != s1.end())
        {
            total1 -= a.second * a.first;
            cnt1 -= a.second;
            s1.erase(s1.find(a));
        }
        else if (s2.find(a) != s2.end())
        {
            s2.erase(s2.find(a));
        }
        for (int i = 0; i < 7; i++)
            cutoff(), balance();
    }
    ll get()
    {
        //cout << "cnt1 = " << cnt1 << endl;
        if (cnt1 <= k) return total1;
        if (s1.size() == 0) return 0;
        ll D = cnt1 - k;
        //assert((*s1.rbegin()).second > D);
        return total1 - D * (*s1.rbegin()).first;
    }
};

void solve()
{
    ll n, m;
    cin >> n >> k >> m;
    vector<vector<pair<ll, ll> > > on(n);
    vector<vector<pair<ll, ll> > > off(n);
    for (int i = 0; i < m; i++)
    {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        l--, r--;
        on[l].push_back({p, c});
        off[r].push_back({p, c});
    }
    ll ans = 0;
    Set2 s;
    for (int i = 0; i < n; i++)
    {
        for (auto e : on[i]) s.insert(e);
        ans += s.get();
        //cout << s.get() << endl;
        for (auto e : off[i]) s.erase(e);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}