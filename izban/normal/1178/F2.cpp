#include <random>

#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

const int MOD = 998244353;


int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int stupid(int n, int m, vector<int> a) {
    const int N = 505;
    static int dp[N][N];
    memset(dp, 0, sizeof(dp));

    for (int len = 1; len <= m; len++) {
        for (int l = 0; l < m; l++) {
            int r = l + len - 1;
            if (r >= m) continue;

            int p = l;
            for (int i = l + 1; i <= r; i++) if (a[i] < a[p]) p = i;


            int sum1 = 0, sum2 = 0;
            for (int i = l; i <= p; i++) {
                int cur = 1;
                if (i > l) cur = mul(cur, dp[l][i - 1]);
                if (i < p) cur = mul(cur, dp[i][p - 1]);
                add(sum1, cur);
            }
            for (int j = p; j <= r; j++) {
                int cur = 1;
                if (j > p) cur = mul(cur, dp[p + 1][j]);
                if (j < r) cur = mul(cur, dp[j + 1][r]);
                add(sum2, cur);
            }
            int res = 1LL * sum1 * sum2 % MOD;

            dp[l][r] = res;
        }
    }
    return dp[0][m - 1];
}

vector<int> uniq(vector<int> a) {
    vector<int> b;
    for (int x : a) {
        if (b.empty() || b.back() != x) b.push_back(x);
    }
    return b;
}

bool bad(int n, vector<int> a) {
    int m = a.size();
    for (int i = 0; i < m; i++) {
        vector<char> was(n);
        for (int j = 0; j < i; j++) was[a[j]] = 1;
        for (int j = i + 1; j < m; j++) {
            if (a[j] > a[i] && was[a[j]]) {
                return 1;
            }
        }
    }
    return 0;
}

int smart(int n, int m, vector<int> a) {
    a = uniq(a);
    m = a.size();

    if (m > 2 * n - 1) return 0;

    if (bad(n, a)) return 0;

    const int N = 1015;
    static int mnL[N][N], mnR[N][N];

    for (int i = 0; i < m; i++) {
        mnL[i][i] = mnR[i][i] = i;
        for (int j = i + 1; j < m; j++) {
            mnL[i][j] = mnL[i][j - 1];
            mnR[i][j] = mnR[i][j - 1];

            if (a[j] < a[mnL[i][j]]) mnL[i][j] = j;
            if (a[j] <= a[mnR[i][j]]) mnR[i][j] = j;

            if (a[i] == a[j]) assert(mnL[i][j] == i && mnR[i][j] == j);
        }
    }

    static int dp[N][N];
//    memset(dp, 0, sizeof(dp));

    for (int len = 1; len <= m; len++) {
        for (int l = 0; l < m; l++) {
            int r = l + len - 1;
            if (r >= m) continue;

            int L = mnL[l][r];
            int R = mnR[l][r];

            int prod = 1;
            int start = -1;
            for (int i = L; i <= R; i++) {
                if (a[i] != a[L]) {
                    if (start == -1) start = i;
                } else {
                    if (start != -1) {
                        prod = mul(prod, dp[start][i - 1]);
                        start = -1;
                    }
                }
            }

            vector<int> right(n), left(n);
            for (int i = l; i <= L; i++) {
                right[a[i]]++;
            }
            int cnt = 0;

            int sum1 = 0, sum2 = 0;
            for (int i = l; i <= L; i++) {
                int cur = 1;
                if (i > l) cur = mul(cur, dp[l][i - 1]);
                if (i < L) cur = mul(cur, dp[i][L - 1]);

                if (cnt == 0) {
                    add(sum1, cur);
                }

                cnt -= right[a[i]] && left[a[i]];
                right[a[i]] -= 1;
                left[a[i]] += 1;
                cnt += right[a[i]] && left[a[i]];
            }

            left.assign(n, 0);
            right.assign(n, 0);
            for (int i = R; i <= r; i++) {
                right[a[i]]++;
            }
            cnt = 0;
            for (int j = R; j <= r; j++) {
                int cur = 1;
                if (j > R) cur = mul(cur, dp[R + 1][j]);
                if (j < r) cur = mul(cur, dp[j + 1][r]);

                cnt -= right[a[j]] && left[a[j]];
                right[a[j]] -= 1;
                left[a[j]] += 1;
                cnt += right[a[j]] && left[a[j]];

                if (cnt == 0) {
                    add(sum2, cur);
                }
            }
            int res = mul(prod, mul(sum1, sum2));

            dp[l][r] = res;
        }
    }
    return dp[0][m - 1];
}



void test() {
    int n = 500;
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(i);
    for (int i = n - 1; i >= 0; i--) a.push_back(i);
//    iota(a.begin(), a.end(), 0);
//    shuffle(a.begin(), a.end(), std::mt19937(239));
    cout << smart(n, a.size(), a) << endl;
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    exit(0);
}

void stress() {
    for (int it = 0;; it++) {
        mt19937 rnd(it);
        db(it);

        int n = rnd() % 500 + 1;
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        shuffle(a.begin(), a.end(), rnd);

        auto ans1 = stupid(n, n, a);
        auto ans2 = smart(n, n, a);
        assert(ans1 == ans2);
    }
}

int slowest(int n, int m, vector<int> a) {
    static map<vector<int>, int> mp;
    static set<pair<int, int>> st;
    if (st.find({n, m}) != st.end()) return mp[a];
    st.insert({n, m});
    function<void(int, vector<int>)> rec = [&](int cur, vector<int> a) {
        if (cur == n) {
            mp[a]++;
            return;
        }
        for (int i = 0; i < m; i++) {
            int mn = n, mx = -1;
            for (int j = 0; j < m; j++) if (a[j] == a[i]) {
                    mn = min(mn, j);
                    mx = max(mx, j);
                }
            auto b = a;
            for (int j = i; j < m; j++) {
                if (a[j] != a[i]) break;
                if (mn >= i && mx <= j) break;
                b[j] = cur;
                rec(cur + 1, b);
            }
        }
    };
    rec(0, vector<int>(m, -1));
    return mp[a];
}

void stress2() {
    for (int m = 1; m <= 20; m++) {
        for (int n = 1; n <= min(m, 9); n++) {
            db2(n, m);
            map<vector<int>, int> mp;
            function<void(int, vector<int>)> rec = [&](int cur, vector<int> a) {
                if (cur == n) {
                    mp[a]++;
                    return;
                }
                for (int i = 0; i < m; i++) {
                    int mn = n, mx = -1;
                    for (int j = 0; j < m; j++) if (a[j] == a[i]) {
                        mn = min(mn, j);
                        mx = max(mx, j);
                    }
                    auto b = a;
                    for (int j = i; j < m; j++) {
                        if (a[j] != a[i]) break;
                        if (mn >= i && mx <= j && a[i] != -1) break;
                        b[j] = cur;
                        rec(cur + 1, b);
                    }
                }
            };
            rec(0, vector<int>(m, -1));
            for (auto it : mp) {
                bool ok = 1;
                ok &= find(it.first.begin(), it.first.end(), -1) == it.first.end();
                for (int i = 0; i < n; i++) ok &= find(it.first.begin(), it.first.end(), i) != it.first.end();
                if (ok) {
                    auto res = smart(n, m, it.first);
                    if (res != it.second) {
                        dbv(it.first);
                        db(it.second);
                        db(res);
                    }
                    assert(res == it.second);
                }
            }
        }
    }
    exit(0);
}

void stress3() {
    for (int it = 0;; it++) {
        mt19937 rnd(it);

        int m = rnd() % 20 + 1;
        int n = rnd() % min(8, m) + 1;

        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            a[i] = rnd() % n;
        }
        bool ok = 1;
        for (int i =0 ; i < n; i++) ok &= find(a.begin(), a.end(), i) != a.end();
        if (!ok) continue;
        db3(it, n, m);

        auto ans1 = smart(n, m, a);
        auto ans2 = slowest(n, m, a);
        if (ans1 != ans2) {
            db2(ans1, ans2);
            db2(n, m);
            dbv(a);
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();
//    stress();
//    stress2();
//    stress3();

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(m);
        for (int i= 0; i < m; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        printf("%d\n", smart(n, m, a));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}