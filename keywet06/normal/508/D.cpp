#include <bits/stdc++.h>
const int N = 200010;
const int W = 62 * 62;
int head[N], nxt[N], to[N], cnt;
int n, ind[N], outd[N], tot;
char s[N], ans[N];
int charToInt(char x) {
    if (isdigit(x)) return x - '0';
    if (islower(x)) return x - 'a' + 10;
    return x - 'A' + 36;
}
char intToChar(int x) {
    if (x < 10) return x + '0';
    if (x < 36) return x - 10 + 'a';
    return x - 36 + 'A';
}
int wordToInt(char x, char y) { return charToInt(x) * 62 + charToInt(y); }
void add(int u, int v) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
void fail() {
    std::cout << "NO" << std::endl;
    exit(0);
}
void dfs(int u) {
    for (int& i = head[u]; i;) {
        int v = to[i];
        i = nxt[i];
        dfs(v);
    }
    ans[--tot] = intToChar(u % 62);
}
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s;
        int u = wordToInt(s[0], s[1]), v = wordToInt(s[1], s[2]);
        ++outd[u], ++ind[v];
        add(u, v);
    }
    int oneMoreIn = 0, oneMoreOut = 0;
    for (int i = 0; i < W; ++i) {
        if (ind[i] == outd[i]) continue;
        if (ind[i] == outd[i] + 1) {
            if (oneMoreIn) fail();
            oneMoreIn = i;
        } else if (ind[i] + 1 == outd[i]) {
            if (oneMoreOut) fail();
            oneMoreOut = i;
        } else
            fail();
    }
    if (!oneMoreOut) {
        for (int i = 0; i < W; ++i) {
            if (outd[i]) {
                oneMoreOut = i;
                break;
            }
        }
    }
    tot = n + 2;
    dfs(oneMoreOut);
    ans[--tot] = intToChar(oneMoreOut / 62);
    if (tot) fail();
    std::cout << "YES" << std::endl;
    std::cout << ans << std::endl;
    return 0;
}