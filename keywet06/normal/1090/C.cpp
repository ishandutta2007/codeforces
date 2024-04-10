#include <bits/stdc++.h>

using namespace std;

const int C = 3;
const int N = 100005;
const int M = 1000005;

bool bo[N];

int n, m, cnt, tp;
int q[N], sz[N], ta[N];
int e[M][3];

vector<int> a[N];
vector<int> b[M];

set<int> S;
set<int>::iterator it;

void ins(int x, int y, int z) {
    e[++cnt][0] = x;
    e[cnt][1] = y;
    e[cnt][2] = z;
}

bool cmp(int x, int y) { return sz[x] < sz[y]; }

int main() {
    scanf("%d%d", &n, &m);
    int i, sum = 0;
    for (i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        sz[i] = t;
        sum += t;
        while (t--) {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    for (i = 1; i <= n; ++i) q[i] = i;
    sort(q + 1, q + n + 1, cmp);
    for (i = 1; i <= n; ++i) ta[q[i]] = sum / n + (n - i + 1 <= sum % n);
    for (i = 1; i <= n; ++i) {
        if (sz[i] < ta[i]) S.insert(i);
    }
    for (i = 1; i <= n; ++i) {
        for (int p : a[i]) b[p].push_back(i);
    }
    for (i = 1; i <= m; ++i) {
        for (int p : b[i]) bo[p] = 1;
        it = S.begin();
        for (int p : b[i]) {
            if (sz[p] > ta[p]) {
                for (; it != S.end(); it++) {
                    int x = *it;
                    if (!bo[x] && sz[x] < ta[x]) {
                        ins(p, x, i);
                        sz[p]--;
                        sz[x]++;
                        if (sz[x] == ta[x]) q[++tp] = x;
                        it++;
                        break;
                    }
                }
            }
        }
        while (tp) S.erase(q[tp--]);
        for (int p : b[i]) bo[p] = 0;
    }
    printf("%d\n", cnt);
    for (i = 1; i <= cnt; ++i) printf("%d %d %d\n", e[i][0], e[i][1], e[i][2]);
    return 0;
}