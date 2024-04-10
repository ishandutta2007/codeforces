#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

void number_sort(ve<int>& p, ve<int>& c) {
    int n = sz(p);
    ve<int> new_p(n), cnt(n), pos(n);
    forn (i, n) cnt[c[i]]++;
    forn (i, n - 1) pos[i + 1] = pos[i] + cnt[i];
    forn (i, n) {
        int x = c[p[i]];
        new_p[pos[x]] = p[i];
        pos[x]++;
    }
    p = new_p;
}

ve<int> sufmas(string s) {
    s.pb('#');
    int n = sz(s);
    ve<int> p(n), b(n);
    ve<pair<char, int>> a(n);
    forn (i, n) a[i] = {s[i], i};
    sort(all(a));
    forn (i, n) p[i] = a[i].se;
    forn (i, n - 1) {
        b[p[i + 1]] = b[p[i]] + (a[i + 1].fi != a[i].fi);
    }
    int k = 0;
    while ((1 << k) < n) {
        forn (i, n) p[i] = (p[i] - (1 << k) + n) % n;
        number_sort(p, b);
        ve<int> new_b(n);
        forn (i, n - 1) {
            pii x = {b[p[i]], b[(p[i] + (1 << k)) % n]};
            pii y = {b[p[i + 1]], b[(p[i + 1] + (1 << k)) % n]};
            new_b[p[i + 1]] = new_b[p[i]] + (x != y);
        }
        b = new_b;
        k++;
    }
    p.erase(p.begin());
    return p;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto res = sufmas(s);
    ve<int> pos(n);
    forn (i, n) pos[res[i]] = i;
    ve<int> lcp(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i] == 0) {
            k = 0;
            continue;
        }
        int j = res[pos[i] - 1];
        while (k + max(i, j) < n && s[i + k] == s[j + k]) k++;
        lcp[pos[i]] = k;
        k = max(0ll, k - 1);
    }
    ve<int> pref(n + 1);
    forn (i, n) pref[i + 1] = pref[i] + (s[i] == '(') - (s[i] == ')');
    map<int, ve<int>> dp;
    forn (i, n + 1) {
        dp[pref[i]].pb(i);
    }
    ve<int> id(n + 1);
    ve<pii> tmp = {{-1e18, n + 1}};
    for (int i = n; i >= 0; i--) {
        while (tmp.back().fi >= pref[i]) tmp.pop_back();
        id[i] = tmp.back().se;
        tmp.pb({pref[i], i});
        //cout << id[i] << endl;
    }
    auto get = [&] (int l, int r) {
        //cout << l << " " << r;
        r = min(r, id[l] - 1);
        int x = pref[l];
        int cnt = upper_bound(all(dp[x]), r + 1) - upper_bound(all(dp[x]), l);
        //cout << " " << cnt << endl;
        return cnt;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += get(res[i], n - 1);
        //cout << ans << " f " << lcp[i] << endl;
        ans -= get(res[i], res[i] + lcp[i] - 1);
        //cout << ans << " " << res[i] << endl;
    }
    cout << ans;
}