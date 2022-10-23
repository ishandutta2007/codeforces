#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acosl(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
const int BIG = (int)(1e9) + (int)(239); // (int)(2e9) + (int)(1e6)
const int MOD = 998'244'353;
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    inline int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    inline void add(int& a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
    }

    inline int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    inline void make_sub(int& a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
    }

    inline int mul(int a, int b) {
        return (ll)a * (ll)b % (ll)MOD;
    }

    inline int power(int a, int k) {
        int ans = 1;
        int pw = a;
        while (k) {
            if (k & 1) {
                ans = mul(ans, pw);
            }
            pw = mul(pw, pw);
            k >>= 1;
        }
        return ans;
    }

    inline int inv(int a) {
        return power(a, MOD - 2);
    }

    inline int div(int a, int b) {
        return mul(a, inv(b));
    }
}

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 200;

int n, q, p[M], a[M], k, s[M];
int l[M], r[M], mn[M], mx[M];
set<pair<int, int>> qq;

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    k = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            k++;
        }
    }
    for (int i = 0; i < n; i++) {
        mn[i] = 0;
        mx[i] = 1'000'000;
    }
    vector<pair<int, int>> st;
    st.emplace_back(-1, 0);
    for (int i = 0; i < n; i++) {
        while (st.size() > 1 && p[st.back().first] < p[i]) {
            auto t = st.back();
            st.pop_back();
            st.back().second = max(st.back().second, t.second);
        }
        l[i] = st.back().first;
        st.back().second = max(st.back().second, a[i]);
        mn[i] = max(mn[i], st.back().second);
        st.emplace_back(i, 0);
    }
    st.clear();
    st.emplace_back(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() > 1 && p[st.back().first] < p[i]) {
            auto t = st.back();
            st.pop_back();
            st.back().second = max(st.back().second, t.second);
        }
        r[i] = st.back().first;
        st.back().second = max(st.back().second, a[i]);
        mn[i] = max(mn[i], st.back().second);
        st.emplace_back(i, 0);
    }
    vector<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
        all.emplace_back(p[i], i);
    }
    sort(all.rbegin(), all.rend());
    for (auto [_, i] : all) {
        if (l[i] != -1) {
            mx[i] = min(mx[i], mx[l[i]]);
        }
        if (r[i] != n) {
            mx[i] = min(mx[i], mx[r[i]]);
        }
        if (a[i] != 0) {
            mx[i] = min(mx[i], a[i]);
        }
    }
    bool ch = true;
    vector<pair<int, int>> seg;
    for (int i = 0; i < n; i++) {
        ch &= (mn[i] <= mx[i]);
        if (a[i] == 0) {
            seg.emplace_back(mn[i], mx[i]);
        } else {
            ch &= (a[i] >= mn[i] && a[i] <= mx[i]);
        }
    }
    for (int i = 0; i < k - 1; i++) {
        cin >> s[i];
    }

    if (!ch) {
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            cout << "NO\n";
        }
        return;
    }

    vector<tuple<int, int, int>> eventst;
    for (int i = 0; i < k; i++) {
        eventst.emplace_back(seg[i].first, 0, i);
        eventst.emplace_back(seg[i].second, 2, i);
    }
    for (int i = 0; i < k - 1; i++) {
        eventst.emplace_back(s[i], 1, -1);
    }
    sort(eventst.begin(), eventst.end());
    auto coordinate = [&]() {
        set<pair<int, int>> q;
        for (auto [xx, type, i] : eventst) {
            if (type == 0) {
                q.insert(make_pair(seg[i].second, i));
            } else if (type == 1) {
                if (q.empty()) {
                    return -1;
                }
                q.erase(q.begin());
            } else {
                if (q.find(make_pair(xx, i)) != q.end()) {
                    return xx;
                }
            }
        }
        return -1;
    };

    auto func = [&](int d) {
        vector<tuple<int, int, int>> events = eventst;
        events.emplace_back(d, 1, -1);
        qq.clear();
        int p = (int)events.size() - 1;
        while (p > 0 && events[p - 1] > events[p]) {
            swap(events[p - 1], events[p]);
            p--;
        }
        for (auto [xx, type, i] : events) {
            if (type == 0) {
                qq.insert(make_pair(seg[i].second, i));
            } else if (type == 1) {
                if (qq.empty()) {
                    return false;
                }
                qq.erase(qq.begin());
            } else {
                if (qq.find(make_pair(xx, i)) != qq.end()) {
                    return false;
                }
            }
        }
        return true;
    };

    int bound = coordinate();

    if (bound == -1) {
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            cout << "NO\n";
        }
        return;
    }

    int l = -1;
    int r = bound;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (!func(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int L = r;
    l = bound;
    r = 1'000'001;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (!func(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    int R = l;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << ((x >= L && x <= R) ? "YES\n" : "NO\n");
    }
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}