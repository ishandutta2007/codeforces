#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double dbl;

void print(vector<int> v) {
    for (int x : v) printf("%d ", x);
    printf("\n");
}

const int K = 2;
const int MOD[K] = {(int)1e9 + 7, (int)1e9 + 9};
struct Hash {
    int a[K];

    Hash() {
        fill(a, a + K, 0);
    }

    Hash(int x) {
        fill(a, a + K, x);
    }

    Hash operator- (const Hash &h) const {
        Hash res;
        for (int i = 0; i < K; i++) {
            res.a[i] = (a[i] - h.a[i] + MOD[i]) % MOD[i];
        }
        return res;
    }

    Hash operator+ (const Hash &h) const {
        Hash res;
        for (int i = 0; i < K; i++) {
            res.a[i] = (a[i] + h.a[i]) % MOD[i];
        }
        return res;
    }

    Hash operator* (const Hash &h) const {
        Hash res;
        for (int i = 0; i < K; i++) {
            res.a[i] = (1LL * a[i] * h.a[i]) % MOD[i];
        }
        return res;
    }

    bool operator< (const Hash &h) const {
        for (int i = 0; i < K; i++) {
            if (a[i] != h.a[i]) return a[i] < h.a[i];
        }
        return 0;
    }

    bool operator== (const Hash &h) const {
        for (int i = 0; i < K; i++) {
            if (a[i] != h.a[i]) return 0;
        }
        return 1;
    }

    bool operator!= (const Hash &h) const {
        return !(*this == h);
    }
};
const Hash Q = Hash(239);
const int N = (int)1.01e6;
Hash p[N];
bool inited = 0;
void init() {
    if (inited) return;
    inited = 1;
    p[0] = Hash(1);
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * Q;
}

const int CMOD = 998244353;
vector<int> solve(int n, vector<vector<int>> a) {
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        iota(b[i].begin(), b[i].end(), 0);
        sort(b[i].begin(), b[i].end(), [&](int x, int y) {
            return a[i][x] < a[i][y];
        });
    }

    init();
    vector<vector<pair<Hash, int>>> vct(n);
    vector<vector<Hash>> sm(n, vector<Hash>(n));
    for (int i = 0; i < n; i++) {
        Hash cur;
        for (int j = 0; j < n; j++) {
            cur = cur + p[b[i][j]];
            sm[i][j] = cur;
            vct[j].push_back({cur, i});
        }
    }
    vector<vector<int>> good(n);
    for (int i = 0; i < n; i++) {
        sort(vct[i].begin(), vct[i].end());
        for (int l = 0; l < n; l++) {
            int r = l;
            while (r < n && vct[i][r].first == vct[i][l].first) r++;

            assert(r - l <= i + 1);
            if (r - l == i + 1) {
                for (int k = l; k < r; k++) {
                    good[vct[i][k].second].push_back(i);
                }
            }
            l = r - 1;
        }
    }

    vector<vector<int>> e(n * 3);
    map<Hash, int> mp;
    set<pair<int, int>> edges;
    auto getid = [&](const Hash &h) {
        auto it = mp.find(h);
        if (it == mp.end()) {
            int sz = mp.size();
            mp[h] = sz;
        }
        return mp[h];
    };
    auto addedge = [&](const Hash &h1, const Hash &h2) {
        int i1 = getid(h1);
        int i2 = getid(h2);
        if (edges.find({i1, i2}) != edges.end()) {
            return;
        }
        edges.insert({i1, i2});
        assert(i2 < (int)e.size());
        e[i2].push_back(i1);
    };
    for (int i = 0; i < n; i++) {
        assert(good[i][0] == 0);
        assert(good[i].back() == n - 1);
        for (int x : good[i]) getid(sm[i][x]);
        for (int j = 1; j < (int)good[i].size(); j++) {
            auto h1 = sm[i][good[i][j - 1]];
            auto h2 = sm[i][good[i][j]];
            addedge(h1, h2);
        }
    }
    assert(mp.size() <= 2 * n);
    int verts = mp.size();

    int root = getid(sm[0][n - 1]);

    vector<int> cnt(verts);
    vector<vector<int>> dp(verts);
    function<void(int)> dfs = [&](int v) {
        cnt[v] = 0;
        dp[v] = vector<int>{1};
        for (int to : e[v]) {
            dfs(to);
            vector<int> ndp(cnt[v] + cnt[to] + 1);
            for (int i = 0; i <= cnt[v]; i++) {
                for (int j = 0; j <= cnt[to]; j++) {
                    ndp[i + j] = (ndp[i + j] + 1LL * dp[v][i] * dp[to][j]) % CMOD;
                }
            }
            dp[v] = ndp;
            cnt[v] += cnt[to];
        }
        cnt[v]++;
        dp[v].resize(dp[v].size() + 1);
        dp[v][1] = (dp[v][1] + 1) % CMOD;
        dp[v][0] = 0;
    };
    dfs(root);
    vector<int> ans;
    for (int i = 1; i <= n; i++) ans.push_back(dp[root][i]);
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        print(solve(n, a));
    }

    return 0;
}