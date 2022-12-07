#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int N = 600005;
const int SIGMA_SIZE = 27;

struct SAM {

    int n;
    int str[N], f[N];
    int sz, last;
    int go[N<<1][SIGMA_SIZE], pre[N<<1], step[N<<1];

    long long r[N<<1];
    int toop[N<<1], pos[N<<1], cnt[N<<1];

    void init() {
        sz = 0, last = 1;
        new_node(0);
        n = 0;
    }

    void new_node(int s) {
        step[++sz] = s;
        pre[sz] = 0;
        memset(go[sz], 0, sizeof(go[sz]));
        pos[sz] = n - 1;
    }

    void ins(int c, int val, int ff) {
        f[n] = ff;
        str[n++] = c;
        new_node(step[last] + 1);
        r[sz] = val;
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
                pre[nq] = pre[q];
                pre[np] = pre[q] = nq;
                for (; p && go[p][c] == q; p = pre[p]) go[p][c] = nq;
            }
        }
        last = np;
    }

    void Toop() {
        for (int i = 0; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= sz; i++) cnt[step[i]]++;
        for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
        for (int i = 1; i <= sz; i++) toop[cnt[step[i]]--] = i;
    }

    long long solve() {
        Toop();
        long long ans = 0;
        for (int i = sz; i >= 1; i--) {
            int id = toop[i];
            r[pre[id]] += r[id];
            int st = pos[id] - step[id] + 1;
            int len = min(pos[id] - f[pos[id]], step[id]);
            if (len > step[pre[id]]) ans = max(ans, r[id] * len);
        }
        return ans;
    }
} gao;

int n;
string str[N];
int c[N];

int main() {
    scanf("%d", &n);
    gao.init();
    for (int i = 0; i < n; i++)
        cin >> str[i];
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    for (int i = 0; i < n; i++) {
        int tmp = gao.n - 1;
        for (int j = 0; j < str[i].length(); j++)
            gao.ins(str[i][j] - 'a', c[i], tmp);
        gao.ins(26, 0, tmp);
    }
    printf("%lld\n", gao.solve());
    return 0;
}