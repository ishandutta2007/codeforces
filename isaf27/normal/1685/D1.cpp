//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int alf = 26;
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
const int BIG = (int)(1e9) + 239;
const int MOD = 998244353; // 1e9 + 7
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    int mul(int a, int b) {
        return 1LL * a * b % MOD;
    }

    int power(int a, int k) {
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

    int inv(int a) {
        return power(a, MOD - 2);
    }
}

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
const int T = (1 << 19) + 239;
const int B = 500;
const int X = 210;

/*vector<int> func(const vector<int>& q) {
    vector<int> res(q.size());
    for (int i = 0; i < (int)q.size(); i++) {
        res[q[i]] = q[(i + (int)q.size() - 1) % (int)q.size()];
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    set<vector<int>> q;
    do {
        q.insert(func(p));
        bool ch = true;
        for (int i = 0; i < (int)p.size(); i++) {
            if (p[i] == i) {
                ch = false;
            }
        }
        if (ch) {
            q.insert(p);
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << q.size() << "\n";
    for (const auto& t : q) {
        for (int i : t) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
}*/

vector<int> inv(const vector<int>& p) {
    vector<int> q(p.size());
    for (int i = 0; i < (int)p.size(); i++) {
        q[p[i]] = i;
    }
    return q;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    while (true) {
        vector<int> cyc(n, -1);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (cyc[i] == -1) {
                int s = i;
                do {
                    cyc[s] = k;
                    s = p[s];
                } while (s != i);
                k++;
            }
        }
        if (k == 1) {
            break;
        }
        bool ok = false;
        for (int i = 0; i < n && !ok; i++) {
            for (int j = i + 1; j < n && !ok; j++) {
                if (abs(p[i] - p[j]) == 1 && cyc[i] != cyc[j]) {
                    swap(p[i], p[j]);
                    ok = true;
                }
            }
        }
    }
    vector<int> pinv = inv(p);
    for (int st = 0; st < n; st++) {
        vector<int> qinv(n, -1);
        qinv[0] = st;
        int s = 0;
        for (int i = 0; i < n - 1; i++) {
            qinv[pinv[s]] = (qinv[s] + 1) % n;
            s = pinv[s];
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (qinv[i] == -1) {
                ok = false;
            }
        }
        if (ok) {
            vector<int> q = inv(qinv);
            for (int i = 0; i < n; i++) {
                cout << q[i] + 1 << " ";
            }
            cout << "\n";
            return;
        }
    }
    assert(false);
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