#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200200;
const int K = 30;

const int SZ = N * K;
int nxt[SZ][2];
int sz;

void init() {
    nxt[0][0] = nxt[0][1] = -1;
    sz = 1;
}

void add(int x) {
    int cur = 0;
    for (int i = K - 1; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (nxt[cur][c] == -1) {
            nxt[sz][0] = nxt[sz][1] = -1;
            nxt[cur][c] = sz++;
        }
        cur = nxt[cur][c];
    }
}

int find(int x) {
    int cur = 0;
    int res = 0;
    for (int i = K - 1; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (nxt[cur][c] == -1) {
            cur = nxt[cur][c ^ 1];
            res += (c ^ 1) << i;
        } else {
            cur = nxt[cur][c];
            res += c << i;
        }
        assert(cur != -1);
    }
    return res;
}

ll solve(vector<int> a, int k) {
    if (a.empty() || k == -1) return 0;
    vector<int> v0, v1;
    for (int x : a) {
        if (x & (1 << k)) v1.push_back(x ^ (1 << k));
        else v0.push_back(x);
    }
    ll res = solve(v0, k - 1) + solve(v1, k - 1);

    if (!v0.empty() && !v1.empty()) {
        init();
        for (int x : v0) {
            add(x);
        }
        int ans = (1 << k);
        for (int y : v1) {
            int z = find(y);
            ans = min(ans, y ^ z);
        }
        assert(ans != (1 << k));
        res += ans ^ (1 << k);
    }
    return res;
}

ll fast(vector<int> a) {
    return solve(a, 29);
}

void test() {
    int n = 2e5;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < K; j++) {
            a[i] = 2 * a[i] + rand() % 2;
        }
    } 
    fast(a);
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
    exit(0);
}

#define TASK "G"
int main() {
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    ///test();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        sort(a.begin(), a.end());
        ll res = fast(a);
        printf("%lld\n", res);
    }
    
    return 0;
}