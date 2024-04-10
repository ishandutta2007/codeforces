#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 1e9 + 7;

int n, l;
char s[205];
int dp[205][105][2][205];

inline void uadd(int &x, int y) {
    x += y - mod;
    x += x >> 31 & mod;
}

struct AC {
    static const int mxn = 205;
    int tot;
    int go[mxn][2];
    int fail[mxn];

    void init() {
        tot = 1;
        memset(go, 0, sizeof(go));
    }

    void insert(char s[], int l) {
        int u = 0;
        rep(i, l) {
            if (!go[u][s[i]]) go[u][s[i]] = tot ++;
            u = go[u][s[i]];
        }
    }

    void build() {
        static int que[mxn];
        int ql = 0, qr = 0;
        rep(c, 2) if (go[0][c]) {
            que[qr ++] = go[0][c];
            fail[go[0][c]] = 0;
        }
        while (ql < qr) {
            int u = que[ql ++];
            rep(c, 2) if (go[u][c]) {
                que[qr ++] = go[u][c];
                fail[go[u][c]] = go[fail[u]][c];
            } else {
                go[u][c] = go[fail[u]][c];
            }
        }
    }
} ac;

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    l = strlen(s);
    rep(i, l) s[i] -= 40;
    ac.init();
    ac.insert(s, l);
    ac.build();
    dp[0][0][0][0] = 1;
    rep(i, n * 2) rep(open, n + 1) rep(found, 2) rep(p, l + 1) {
        int v;
        if ((v = dp[i][open][found][p])) {
            rep(c, 2) {
                int nopen = open + (c == 0 ? +1 : -1);
                int np = ac.go[p][c];
                bool nfound = found | (np == l);
                if (nopen < 0) continue;
                uadd(dp[i + 1][nopen][nfound][np], v);
            }
        }
    }
    int ans = 0;
    rep(p, l + 1) uadd(ans, dp[n * 2][0][1][p]);
    printf("%d\n", ans);
    return 0;
}