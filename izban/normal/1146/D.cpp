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

mt19937 rnd(clock());

const int INF = 1.01e9;

// sum(i=0..n-1) (a+b*i) div m
ll solve(ll n, ll a, ll b, ll m) {
    if (b == 0) return n * (a / m);
    if (a >= m) return n * (a / m) + solve(n, a % m, b, m);
    if (b >= m) return n * (n - 1) / 2 * (b / m) + solve(n, a, b % m, m);
    return solve((a + b * n) / m, (a + b * n) % m, m, b);
}


ll solve(int m, int a, int b) {
    int N = a + b;

    vector<int> mn(N, INF);

    set<pair<int, int>> st;

    mn[0] = 0;
    st.insert({0, 0});
    while (!st.empty()) {
        int x = st.begin()->second;
        st.erase(st.begin());
        {
            if (x + a < N) {
                if (mn[x + a] > max(mn[x], x + a)) {
                    st.erase({mn[x + a], x + a});
                    mn[x + a] = max(mn[x], x + a);
                    st.insert({mn[x + a], x + a});
                }
            }
            if (x - b >= 0) {
                if (mn[x - b] > max(mn[x], x - b)) {
                    st.erase({mn[x - b], x - b});
                    mn[x - b] = max(mn[x], x - b);
                    st.insert({mn[x - b], x - b});
                }
            }
        }
    }

    for (int i = 0; i + a < N; i++) {
        assert(mn[i] <= mn[i + a]);
    }
//    dbv(mn);

    ll ans = 0;
    for (int i = 0; i < a; i++) {
        if (mn[i] <= m) {
            // sum(x=mn[i]..m) (x-i) div a + 1
            // sum(x=0..m-mn[i]) (x+a-i+mn[i]) div a
            ans += solve(m - mn[i] + 1, a-i+mn[i], 1, a);
        }
    }

    return ans;
}

ll slow(int m, int a, int b) {
    ll ans = 0;
    for (int n = 0; n <= m; n++) {
        vector<int> can(n + 1);
        queue<int> q;
        can[0] = 1;
        q.push(0);
        while (!q.empty()) {
            int v= q.front();
            q.pop();
            if (v + a <= n && !can[v + a]) {
                can[v + a] = 1;
                q.push(v + a);
            }
            if (v - b >= 0 && !can[v - b]) {
                can[v - b] = 1;
                q.push(v - b);
            }
        }
        int sum = 0;
        for (int x : can) sum += x;
        ans += sum;
    }
    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

//    for (int a = 1; a <= 30; a++) {
//        for (int b = 1; b <= 30; b++) {
//            for (int m = 1; m <= 30; m++) {
//                ll ans1 = solve(m, a, b);
//                ll ans2 = slow(m, a, b);
//                if (ans1 != ans2) {
//                    db2(ans1, ans2);
//                    db3(m, a, b);
//                    return 0;
//                }
//            }
//        }
//    }

    int m, a, b;
    while (cin >> m >> a >> b) {
        cout << solve(m, a, b) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}