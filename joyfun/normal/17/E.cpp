#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2000005;
const int SIGMA_SIZE = 26;
const int MOD = 51123987;

struct PAM {
    int next[N];
    int L[N];
    int sz, last;

    int head[N];
    int son[N];
    int to[N];

    int num[N];
    int sum[N];

    int n;
    char str[N];

    int new_node(int x) {
        head[sz] = -1;
        L[sz] = x;
        return sz++;
    }

    void init() {
        sz = 0;
        new_node(0);
        new_node(-1);
        next[0] = 1;
        last = 0;
    }

    int get_next(int x, int sn) {
        while (str[sn - L[x] - 1] != str[sn]) x = next[x];
        return x;
    }

    int find(int u, int c) {
        for (int i = head[u]; i + 1; i = son[i]) {
            if (to[i] == c) return i;
        }
        return 0;
    }

    int add(int c, int id) {
        int u = get_next(last, id);
        if (!find(u, c)) {
            int p = new_node(L[u] + 2);
            next[p] = find(get_next(next[u], id), c);
            son[p] = head[u]; head[u] = p; to[p] = c;
            num[p] = num[next[p]] + 1;
        }
        last = find(u, c);
        return num[last];
    }

    void solve() {
        str[0] = '#';
        scanf("%d%s", &n, str + 1);
        init();
        reverse(str + 1, str + 1 + n);
        for (int i = 1; i <= n; i++)
            sum[n - i + 1] = (sum[n - i + 2] + add(str[i] - 'a', i)) % MOD;
        init();
        int ans = 0;
        reverse(str + 1, str + 1 + n);
        int tot = sum[1];
        for (int i = 1; i <= n; i++) ans = (ans + (long long)sum[i + 1] * add(str[i] - 'a', i) % MOD) % MOD;
        printf("%d\n", ((long long)tot * (tot - 1) / 2 % MOD - ans + MOD) % MOD);
    }
} gao;

int main() {
    gao.solve();
    return 0;
}