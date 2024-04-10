#pragma GCC optimize("Ofast")
/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 31607; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 25;

int n, k;
string a, b;

tuple<string, int, int> inner(const string& s) {
    int l = -1;
    int r = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') {
            if (l == -1) {
                l = i;
            }
            r = i;
        }
    }
    return make_tuple(s.substr(l, r - l + 1), l, r);
}

void operation(vector<pair<int, int>>& ans, string& s, int l, int r) {
    ans.emplace_back(l, r);
    reverse(s.begin() + l, s.begin() + r + 1);
}

template <typename T>
void extend(vector<T>& va, const vector<T>& vb) {
    for (const auto& t : vb) {
        va.template emplace_back(t);
    }
}

vector<pair<int, int>> unite(string& s, int l, int r) {
    vector<pair<int, int>> ans;
    int f = 0;
    while (true) {
        int il = -1;
        int ir = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == '1') {
                if (il == -1) {
                    il = i;
                }
                ir = i;
            }
        }
        if (ir - il == k) {
            operation(ans, s, l, ir - 1);
            break;
        }
        if (f == 0) {
            operation(ans, s, il, ir - 1);
        } else {
            operation(ans, s, il + 1, ir);
        }
        f = 1 - f;
    }
    return ans;
}

vector<pair<int, int>> solve(string& s) {
    vector<pair<int, int>> ans;
    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        sum += (s[i] - '0');
    }
    while (true) {
        int cnt = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt = i;
                break;
            }
        }
        if (sum - cnt <= 1) {
            break;
        }
        if (sum - cnt >= k + 1) {
            int cur = 0;
            for (int i = cnt; i < n; i++) {
                cur += (s[i] - '0');
                if (cur == k + 1) {
                    extend(ans, unite(s, cnt, i));
                    break;
                }
            }
            continue;
        }
        int cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur += (s[i] - '0');
            if (cur == k + 1) {
                extend(ans, unite(s, i, n - 1));
                break;
            }
        }
        break;
    }
    /*if (k == 1) {
        // merge last two things
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt = i;
                break;
            }
        }
        int pos = -1;
        for (int i = cnt; i < n; i++) {
            if (s[i] == '1') {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            operation(ans, s, pos, n - 1);
        }
    */
    if (k % 2 == 1) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt = i;
                break;
            }
        }
        int pos = -1;
        for (int i = cnt; i < n; i++) {
            if (s[i] == '1') {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            int l = cnt - k;
            int r = pos;
            for (int i = 0; i < k; i++) {
                if (i % 2 == 0) {
                    operation(ans, s, l + 1, r);
                } else {
                    operation(ans, s, l, r - 1);
                }
            }
        }
    }
    return ans;
}

void solve() {
    cin >> n >> k >> a >> b;
    if (a == b) {
        cout << "0\n";
        return;
    }
    if (k == 0) {
        cout << "-1\n";
        return;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] - '0');
    }
    int sumb = 0;
    for (int i = 0; i < n; i++) {
        sumb += (b[i] - '0');
    }
    if (sum != sumb || sum < k || sum == n) {
        cout << "-1\n";
        return;
    }
    if (sum == k) {
        auto ia = inner(a);
        auto ib = inner(b);
        if (get<0>(ia) == get<0>(ib)) {
            cout << "2\n";
            cout << 1 << " " << get<2>(ia) + 1 << "\n";
            cout << 1 << " " << get<2>(ib) + 1 << "\n";
            return;
        }
        reverse(get<0>(ia).begin(), get<0>(ia).end());
        if (get<0>(ia) == get<0>(ib)) {
            cout << "3\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n - get<1>(ia) << "\n";
            cout << 1 << " " << get<2>(ib) + 1 << "\n";
            return;
        }
        cout << "-1\n";
        return;
    }
    //cerr << "kek!\n";
    auto v1 = solve(a);
    auto v2 = solve(b);
    //cerr << a << " " << b << "\n";
    if (a == b) {
        vector<pair<int, int>> ans = v1;
        reverse(v2.begin(), v2.end());
        extend(ans, v2);
        cout << ans.size() << "\n";
        for (const auto& t : ans) {
            cout << t.first + 1 << " " << t.second + 1 << "\n";
        }
        return;
    }
    cout << "-1\n";
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