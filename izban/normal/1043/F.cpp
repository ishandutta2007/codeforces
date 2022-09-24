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

const int INF = 1e9;

int solve(vector<int> a) {
    int n = a.size();
    int g = 0;
    for (int x : a) g = __gcd(g, x);

    if (g != 1) {
        return -1;
    }

    const int N = 300300;
    vector<int> pr;
    vector<int> lp(N);
    iota(lp.begin(), lp.end(), 0);
    vector<vector<int>> div(N);

    for (int i = 1; i < N; i++) div[i].push_back(1);
    for (int i = 2; i < N; i++) {
        if (lp[i] == i) {
            pr.push_back(i);
        }
        for (int j = i; j < N; j += i) {
            lp[j] = min(lp[j], lp[i]);
            div[j].push_back(i);
        }
    }
    vector<int> mob(N, 0);
    mob[1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = i + i; j < N; j += i) {
            mob[j] -= mob[i];
        }
    }

    vector<int> na;
    for (int x : a) {
        int z = 1;
        while (x > 1) {
            int y = lp[x];
            z *= y;
            while (x % y == 0) x /= y;
        }
        na.push_back(z);
    }
    sort(na.begin(), na.end());
    na.resize(unique(na.begin(), na.end()) - na.begin());
    a = na;


    vector<ll> o(N);
    for (int x : a) {
        for (int d : div[x]) {
            o[d] += mob[d];
        }
    }

    vector<ll> cnt(N);
    for (int i = 0; i < N; i++) {
        for (int d : div[i]) {
            cnt[i] += o[d];
        }
    }

    vector<int> dp(N, INF);
    dp[1] = 0;
    for (int i = 2; i < N; i++) {
        for (int d : div[i]) {
            if (cnt[i / d] > 0) {
                dp[i] = min(dp[i], dp[d] + 1);
            }
        }
    }

    int ans = INF;
    for (int x : a) ans = min(ans, 1 + dp[x]);

    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        cout << solve(a) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}