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

/*map<vector<int>, int> mp;
map<vector<int>, vector<int>> pr;

int rec(vector<int> a) {
    if (!mp.count(a)) {
        if (a == vector<int>(a.size(), 0)) {
            return mp[a] = 0;
        }

        mp[a] = INF;
        int res = INF;
        vector<int> vct;
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = i + 1; j + (j - i) < (int)a.size(); j++) {
                auto b = a;
                b[i] ^= 1;
                b[j] ^= 1;
                b[j + (j - i)] ^= 1;
                int nval = rec(b) + 1;
                if (res > nval) {
                    res = nval;
                    vct.clear();
                    vct.push_back(i);
                    vct.push_back(j);
                    vct.push_back(j + j - i);
                }
            }
        }
        mp[a] = res;
        pr[a] = vct;
    }
    return mp[a];
}*/

vector<int> dp;
vector<pair<int, int>> pr;

void work(int n, bool can) {
    dp.assign(1 << n, INF);
    pr.resize(1 << n);

    queue<int> q;
    q.push(0);
    dp[0] = 0;
    while (!q.empty()) {
        int mask = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            for (int d = 1; i + 2 * d < 2 * n; d++) {
                if (i + 2 * d >= n && !can) continue;

                int nmask = mask;
                nmask ^= 1 << i;
                if (i + d < n) nmask ^= 1 << (i + d);
                if (i + d + d < n) nmask ^= 1 << (i + d + d);
                if (dp[nmask] > dp[mask] + 1) {
                    dp[nmask] = dp[mask] + 1;
                    pr[nmask] = make_pair(i, d);
                    q.push(nmask);
                }
            }
        }
    }
    //cout << *max_element(dp.begin(), dp.end()) << endl;
    int mx = 0;
    for (int i = 0; i < (1 << n); i++) {
        //if (!(i & 1)) continue;
        mx = max(mx, dp[i]);
    }
    //cerr << mx << endl;
}

vector<pair<int, int>> fast(vector<int> a) {
    int n = a.size();

    int T = 6;
    work(6, 1);

    vector<pair<int, int>> ans;

    int i;
    auto go = [&](int cmask) {
        while (cmask) {
            auto o = pr[cmask];
            ans.push_back({i + o.first, o.second});
            cmask ^= 1 << o.first;
            if (o.first + o.second < T) cmask ^= 1 << (o.first + o.second);
            if (o.first + o.second + o.second < T) cmask ^= 1 << (o.first + o.second + o.second);
            a[i + o.first] ^= 1;
            a[i + o.first + o.second] ^= 1;
            a[i + o.first + o.second + o.second] ^= 1;
        }
    };

    for (i = 0; i + 2 * T <= n; i += T) {
        int cmask = 0;
        for (int j = 0; j < T; j++) cmask |= a[i + j] << j;
        go(cmask);
    }
    for (int j = 0; j < i; j++) assert(a[j] == 0);
    i = max(0, n - T * 3);
    T = n - i;
    work(T, 0);

    int cmask = 0;
    for (int j = 0; i + j < n; j++) cmask |= a[i + j] << j;

    if (dp[cmask] == INF) {
        return vector<pair<int, int>>(1, make_pair(-1, -1));
    }
    go(cmask);
    for (int j = 0; j < n; j++) assert(a[j] == 0);

    assert(ans.size() <= n / 3 + 12);
    return ans;
}

void print(vector<pair<int, int>> a) {
    if (a.size() == 1 && a[0].first == -1) {
        printf("NO\n");
    } else {
        printf("YES\n%d\n", (int)a.size());
        for (auto o : a) printf("%d %d %d\n", o.first + 1, o.first + 1 + o.second, o.first + 1 + o.second + o.second);
    }
}

void stress() {
    for (int it = 0;; it++) {
        db(it);
        srand(it);

        //int len = rand() % 5 + 1;
        int len = rand() % 5 + 1;
        int n = 0;
        for (int i = 0; i < len; i++) n = 10 * n + rand() % 10;
        if (n == 0) continue;
        db(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = rand() % 2;

        auto ans = fast(a);
        db(ans.size());
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    //stress();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        print(fast(a));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}