#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1000, D = 50, M = 25000, P = 1E9 + 7;
string ss, sx, sy;
int n, d;
int s[N], x[D], y[D], dp[2][2][M];
int cnt_nodes = 2;
struct Node {
    int next[10];
    int link;
    Node() : next{}, link(0) {}
} t[M];
void inc(int &a, int b) {(a += b) >= P ? a -= P : 0;}
void build() {
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (int i = 0; i < 10; ++i) {
            if (t[p].next[i] == 0) {
                t[p].next[i] = t[t[p].link].next[i];
            } else if (t[p].next[i] != 2) {
                t[t[p].next[i]].link = t[t[p].link].next[i];
                que.push(t[p].next[i]);
            }
        }
    }
}
int solve(int x[D], bool equal) {
    int cur = 0;
    memset(dp[cur], 0, sizeof(dp[cur]));
    dp[cur][0][1] = 1;
    for (int i = 0; i < d; ++i) {
        cur ^= 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int l = 0; l < 2; ++l)
            for (int p = 1; p <= cnt_nodes; ++p)
                if (dp[cur ^ 1][l][p] != 0)
                    for (int v = 0; v < 10; ++v)
                        if (l || v <= x[i])
                            inc(dp[cur][l || v < x[i]][t[p].next[v]], dp[cur ^ 1][l][p]);
    }
    return (dp[cur][1][2] + (equal ? dp[cur][0][2] : 0)) % P;
}
int main() {
    for (int i = 0; i < 10; ++i)
        t[0].next[i] = 1;
    for (int i = 0; i < 10; ++i)
        t[2].next[i] = 2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> ss >> sx >> sy;
    n = ss.length();
    d = sx.length();
    for (int i = 0; i < n; ++i)
        s[i] = ss[i] - '0';
    for (int i = 0; i < d; ++i)
        x[i] = sx[i] - '0';
    for (int i = 0; i < d; ++i)
        y[i] = sy[i] - '0';
    for (int i = 0; i + d / 2 <= n; ++i) {
        int p = 1;
        for (int j = i; j < i + d / 2 - 1; ++j) {
            if (t[p].next[s[j]] == 0)
                t[p].next[s[j]] = ++cnt_nodes;
            p = t[p].next[s[j]];
        }
        t[p].next[s[i + d / 2 - 1]] = 2;
    }
    build();
    cout << (solve(y, true) - solve(x, false) + P) % P << endl;
    return 0;
}