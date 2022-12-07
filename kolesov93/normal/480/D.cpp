#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
const int N = 612;
const int M = 2024;

ll f[N][M];
int in[N], out[N], w[N], s[N], cost[N];

struct cell {
    int id;
    bool left;

    int getTime() const {
        if (left) return in[id];
        return out[id];
    }

    bool operator<(const cell& A) const {
        int t1 = getTime(), t2 = A.getTime();
        if (t1 != t2) return t1 < t2;
        if (left != A.left) return !left;
        if (left) {
            return out[id] > out[A.id];
        }
        return in[id] > in[A.id];
    }
} ev[N + N];
int kev = 0;

int inid[N], outid[N];
int len[N], order[N];
vector<int> g[N];

ll F[M];

bool cmp(int a, int b) {
    return len[a] < len[b];
}
bool rcmp(int a, int b) {
    return outid[a] < outid[b];
}

int main() {
    int n, S;
    cin >> n >> S;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d%d", in + i, out + i, w + i, s + i, cost + i);
        ev[kev].id = i;
        ev[kev].left = true;
        ++kev;
        ev[kev].id = i;
        ev[kev].left = false;
        ++kev;
    }
    ev[kev].id = n;
    ev[kev + 1].id = n;
    ev[kev].left = true;
    ev[kev + 1].left = false;
    w[n] = 0; s[n] = S; cost[n] = 0;
    in[n] = -1; out[n] = 1001;
    kev += 2;
    n++;
    sort(ev, ev + kev);

    for (int i = 0; i < kev; ++i) {
        if (ev[i].left) inid[ev[i].id] = i;
        else outid[ev[i].id] = i;
    }
    for (int i = 0; i < n; ++i) {
        len[i] = outid[i] - inid[i];
        order[i] = i;
    }
    sort(order, order + n, cmp);

    for (int i = 0; i < n; ++i) {
        int who = order[i];
        for (int j = 0; j < i; ++j) {
            int cand = order[j];
            if (inid[who] <= inid[cand] && outid[cand] <= outid[who]) {
                g[who].push_back(cand);
            }
        }
        sort(g[who].begin(), g[who].end(), rcmp);
    }

    for (int i = 0; i < n; ++i) {
        int x = order[i];

        for (int maxs = 0; maxs <= S; ++maxs) {
            int lims = maxs;
            if (lims < 0) continue;

            int pos = inid[x];
            F[pos] = 0;
            for (int j = 0; j < g[x].size(); ++j) {
                int cand = g[x][j];
                if (w[cand] > lims) continue;
                int cpos = outid[cand];
                while (pos < cpos) {
                    F[pos + 1] = F[pos];
                    ++pos;
                }

                int lpos = inid[cand] - 1;
                ll value = 0;
                if (lpos >= inid[x] && lpos >= 0) value = F[lpos];

                F[pos] = max(F[pos], value + f[cand][lims]);
            }

            ll result = F[pos];
            f[x][maxs] = result;
        }

        for (int j = S; j >= 0; --j) {
            int got = min(j - w[x], s[x]);
            if (got >= 0) {
                f[x][j] = max(f[x][j], f[x][got] + cost[x]);
            }
        }
        for (int j = 1; j <= S; ++j) {
            f[x][j] = max(f[x][j - 1], f[x][j]);
        }
    }

    cout << f[n - 1][S] << endl;

    return 0;
}