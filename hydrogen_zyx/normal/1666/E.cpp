#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;


pair<ll, ll> merge_pair(pair<ll, ll> a, pair<ll, ll> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

pair<ll, ll> add_pair(pair<ll, ll> a, pair<ll, ll> b) {
    return {a.first + b.first, a.second + b.second};
}

ll l, n;
ll a[N];

vector<ll> ans;
vector<pair<ll, ll> > range;
vector<pair<int, int> > ansout;

ll solve2(ll st, ll lg, bool out) {
    pair<ll, ll> now = {0, 0};
    ll res;
    for (ll i = 1; i <= n; i++) {
        now = add_pair(now, make_pair(st, lg));


        if (i == n) {
            if (now.first <= a[i + 1] && a[i + 1] <= now.second) {
                res = 0;
                break;
            } else if (now.first > a[i + 1]) {
                res = 1;
                break;
            } else if (now.second < a[i + 1]) {
                res = -1;
                break;
            }
        } else {
            if (now.second < a[i]) {
                res = -1;
                break;
            }
            if (now.first > a[i + 1]) {
                res = 1;
                break;
            }
        }
        now = merge_pair(now, make_pair(a[i], a[i + 1]));
        if (out) {
            range.push_back(now);
//            cout << now.first << ' ' << now.second << endl;
        }
    }
    if (out) {
        now = {l, l};
        ans.push_back(l);
        for (ll i = n - 1; i >= 1; i--) {
            now = add_pair(now, make_pair(-lg, -st));
            now = merge_pair(now, range[i - 1]);
            now = make_pair(now.first, now.first);
            ans.push_back(now.first);
        }
        reverse(ans.begin(), ans.end());
        ll pre = 0;
        for (auto x: ans) {
            ansout.push_back({pre, x});
            pre = x;
        }
    }
    return res;
}


bool solve1(ll mid1, bool out) {
    ll l2 = 0, r2 = l;
    while (l2 < r2) {
        ll mid2 = (l2 + r2) >> 1;
        ll res = solve2(mid2, mid2 + mid1, 0);
        if (res < 0) {
            l2 = mid2 + 1;
        } else {
            r2 = mid2;
        }
    }
    return solve2(l2, l2 + mid1, out) == 0;
}

bool spj(int l1) {
    int mmin = 0x3f3f3f3f;
    int mmax = 0;
    for (int i = 1; i <= n; i++) {
        mmin = min(mmin, ansout[i - 1].second - ansout[i - 1].first);
        mmax = max(mmax, ansout[i - 1].second - ansout[i - 1].first);
        assert(ansout[i - 1].first <= a[i]);
        assert(a[i] <= ansout[i - 1].second);
    }
    assert(l1 == mmax - mmin);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

//    srand(time(0));
    cin >> l >> n;
//    l = 100000;
//    n = 3000;
//    set<int> st;

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
//        a[i] = rand() % (l - 1) + 1;
//        while (st.count(a[i])) {
//            a[i] = rand() % (l - 1) + 1;
//        }
//        st.insert(a[i]);
    }
//    sort(a + 1, a + 1 + n);
//    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//    cout << endl;
    a[n + 1] = l;
    ll l1 = 0, r1 = l;
    while (l1 < r1) {
        ll mid1 = (l1 + r1) >> 1;
        if (solve1(mid1, 0)) {
            r1 = mid1;
        } else {
            l1 = mid1 + 1;
        }
    }
    solve1(l1, 1);
//    cout << l1 << endl;

    for (auto x: ansout) cout << x.first << ' ' << x.second << endl;
//    spj(l1);
}