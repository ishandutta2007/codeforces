#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 500005;
const int SIGMA_SIZE = 2;

int n;
char str[N];

struct SAM {
    int sz, last;
    int go[N<<1][SIGMA_SIZE], pre[N<<1], step[N<<1], pos[N<<1];
    int st[N], top, up[N][25];

    void new_node(int s) {
        step[++sz] = s;
        pre[sz] = 0;
        memset(go[sz], 0, sizeof(go[sz]));
    }

    void build() {
        sz = 0, last = 1;
        new_node(0);
        for (int i = 1; i <= n; i++) {
            new_node(step[last] + 1);
            pos[sz] = i;
            int c = (str[i] == ')');
            int p = last, np = sz;
            for (; p && !go[p][c]; p = pre[p]) go[p][c] = np;
            if (!p) pre[np] = 1;
            else {
                int q = go[p][c];
                if (step[q] == step[p] + 1) pre[np] = q;
                else {
                    new_node(step[p] + 1);
                    int nq = sz;
                    for (int j = 0; j < SIGMA_SIZE; j++) go[nq][j] = go[q][j];
                    pos[nq] = pos[q]; pre[nq] = pre[q];
                    pre[np] = pre[q] = nq;
                    for (; p && go[p][c] == q; p = pre[p]) go[p][c] = nq;
                }
            }
            last = np;
        }
    }

    int cal(int v, int len) {
        int ans = 0;
        for (int i = 21; i >= 0; i--) {
            if (up[v][i] && v - up[v][i] + 1 <= len) {
                len -= v - up[v][i] + 1;
                v = up[v][i] - 1;
                ans += (1<<i);
            }
        }
        return ans;
    }

    void solve() {
        scanf("%d", &n);
        scanf("%s", str + 1);
        build();
        for (int i = 1; i <= n; i++) {
            if (str[i] == '(') st[top++] = i;
            else if (top) {
                top--;
                up[i][0] = st[top];
                for (int j = 1; j < 22 && up[i][j - 1] - 1; j++)
                    up[i][j] = up[up[i][j - 1] - 1][j - 1];
            }
        }
        long long ans = 0;
        for (int i = 2; i <= sz; i++)
            ans += cal(pos[i], step[i]) - cal(pos[i], step[pre[i]]);
        printf("%lld\n", ans);
    }
} gao;

int main() {
    gao.solve();
    return 0;
}