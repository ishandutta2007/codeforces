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

pair<int, int> solve(vector<int> a) {
    int n = a.size();

    int pos = min_element(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n * 2; i++) a.push_back(a[i]);

    vector<int> dp(a.size());
    auto calc_h = [&](int l, int r) {
        vector<int> st;

        auto put = [&](int i) {
            dp[i] = 1;
            int last = 0;
            while (!st.empty() && a[st.back()] > a[i]) {
                dp[st.back()] = max(dp[st.back()], last + 1);
                last = dp[st.back()];
                st.pop_back();
            }
            dp[i] = last + 1;
            st.push_back(i);
        };

        for (int i = l; i <= r; i++) {
            put(i);
        }
        int old = a[r + 1];
        a[r + 1] = -1;
        put(r + 1);
        a[r + 1] = old;
        return dp[r + 1] - 1;
    };

    int L = -1, R = n;
    while (R - L > 1) {
        int M = (L + R) >> 1;

        int elems_left = M;
        int elems_right = n - 1 - elems_left;

        int h_right = calc_h(pos + 1, pos + elems_right);
        int h_left = calc_h(pos + elems_right + 1, pos + n - 1);

        if (h_left < h_right) {
            L = M;
        } else {
            R = M;
        }
    }

    int first_pos = pos - R;
    if (first_pos < 0) first_pos += n;

    a.resize(n);
    rotate(a.begin(), a.begin() + first_pos, a.end());
    int res = calc_h(0, n - 1);

    return make_pair(res, first_pos);
}

pair<int, int> slow(vector<int> a) {
    auto subsolve = [&](vector<int> a) {
        function<int(int, int)> rec = [&](int l, int r) {
            if (l > r) return 0;
            if (l == r) return 1;
            int m = l;
            for (int i = l + 1; i <= r; i++) if (a[i] < a[m]) m = i;
            return 1 + max(rec(l, m - 1), rec(m + 1, r));
        };
        return make_pair(rec(0, a.size() - 1), -1);
    };

    pair<int, int> ans = make_pair(1e9, -1);
    int n = a.size();
    for (int i = 0; i < n; i++) {
        ans = min(ans, subsolve(a));
        rotate(a.begin(), a.begin() + 1, a.end());
    }
    return ans;
}

void stress() {
    for (int it = 0;; it++ ){
        db(it);
        mt19937 rnd(it);
        int n = rnd() % 100 + 1;
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin(), p.end(), rnd);

        auto ans1 = solve(p);
        auto ans2 = slow(p);
        db2(ans1.first, ans2.first);
        assert(ans1.first == ans2.first);
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    stress();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        auto o = solve(a);
        cout << o.first << " " << o.second << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}