#include <bits/stdc++.h>
using namespace std;

const int B = 2;
const int C = 3;
const int D = 4;
const int E = 44;
const int N = 7000000;

bool sel[N], sgn[N];
bool cn[N][C];

char s[E];

short val[N];

int T = 1;
int e[D];
int dp[N], fa[N];
int chd[N][B];

void dfs(int u) {
    cn[u][1] = cn[u][2] = 0;
    cn[u][val[u]] = 1;
    for (int i = 0; i < 2; ++i) {
        int v = chd[u][i];
        if (!v) continue;
        dp[v] = dp[u] + 1;
        dfs(v);
        for (int j = 1; j <= 2; j++) cn[u][j] |= cn[v][j];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        int x = 0, tp = 1;
        int j;
        for (j = len - 1; j >= 0; j--) {
            if (s[j] == '/') break;
            x = (s[j] - '0') * tp + x;
            tp *= 10;
        }
        if (j == -1) x = 32;
        long long X = 0;
        for (int c = 0, j = 1; c < D; c++) {
            int d = 0;
            for (; s[j] != '.' && s[j] != '/' && j < len; j++)
                d = d * 10 + s[j] - '0';
            j++;
            X = X << 8 | d;
        }
        if (((1LL << (32 - x)) - 1) & X) return puts("-1"), 0;
        int root = 1;
        for (j = 0; j < x; j++) {
            int c = X >> (31 - j) & 1;
            if (!chd[root][c]) chd[root][c] = ++T, fa[T] = root, sgn[T] = c;
            root = chd[root][c];
        }
        int t = (s[0] == '-' ? 1 : 2);
        if (val[root] + t == C) return puts("-1"), 0;
        val[root] = t;
    }
    dfs(1);
    for (int i = 1; i <= T; ++i)
        if (val[i]) {
            if (cn[i][C - val[i]]) return puts("-1"), 0;
            if (val[i] == 2) continue;
            int j = i;
            while (j > 1 && !cn[fa[j]][2]) j = fa[j];
            sel[j] = 1;
        }
    int tot = 0;
    for (int i = 1; i <= T; ++i) tot += sel[i];
    cout << tot << endl;
    for (int i = 1; i <= T; ++i) {
        if (!sel[i]) continue;
        int j = i, x = 0;
        long long tp = (1LL << (32 - dp[i]));
        long long X = 0;
        while (j != 1) {
            X += tp * sgn[j], j = fa[j], tp *= 2, x++;
        }
        for (int c = 0; c < D; ++c) e[c] = X % 256, X /= 256;
        printf("%d.%d.%d.%d", e[C], e[2], e[1], e[0]);
        if (x < 32) printf("/%d", x);
        puts("");
    }
    return 0;
}