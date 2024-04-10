#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 N = 1e5 + 5;

bool il[65][1 << 11];

char st[N], top;
char s[15][N];

int64 T, n, ans = 0;
int64 ln[N], id[N];
int64 pos[15][65][2];
int64 deg[52][1 << 10], f[52][1 << 10];

pair<int64, int64> pre[52][1 << 10];

vector<pair<int64, int64>> adj[52][1 << 10];

queue<pair<int64, int64>> q;

void topo() {
    for (int i = 0; i < 52; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if (il[i][j] && deg[i][j] == 0) {
                q.push(make_pair(i, j));
                f[i][j] = 1;
                pre[i][j] = make_pair(-1, 0);
            }
        }
    }
    ans = 0;
    while (!q.empty()) {
        int64 ch = q.front().first, S = q.front().second;
        q.pop();
        ans = max(ans, f[ch][S]);
        for (auto pfr : adj[ch][S]) {
            int64 t = pfr.first, Sk = pfr.second;
            f[t][Sk] = f[ch][S] + 1;
            --deg[t][Sk];
            pre[t][Sk] = make_pair(ch, S);
            if (deg[t][Sk] == 0) q.push(make_pair(t, Sk));
        }
    }
    cout << ans << endl;
    for (int i = 0; i < 52; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if (il[i][j] && f[i][j] == ans) {
                int64 nw = i, nwS = j;
                top = 0;
                while (~nw) {
                    st[++top] = nw;
                    pair<int64, int64> fr = pre[nw][nwS];
                    nw = fr.first, nwS = fr.second;
                }
                while (top) {
                    if (st[top] < 26) {
                        cout << (char)('A' + st[top]);
                    } else {
                        cout << (char)('a' + st[top] - 26);
                    }
                    --top;
                }
                cout << endl;
                return;
            }
        }
    }
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    for (int i = 0; i < 26; ++i) id[i + 'A'] = i;
    for (int i = 0; i < 26; ++i) id[i + 'a'] = 26 + i;
    while (T--) {
        memset(pos, 0, sizeof(pos));
        memset(deg, 0, sizeof(deg));
        memset(il, 0, sizeof(il));
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> (s[i] + 1);
            ln[i] = strlen(s[i] + 1);
            for (int j = 1; j <= ln[i]; ++j) {
                if (pos[i][id[s[i][j]]][0]) {
                    pos[i][id[s[i][j]]][1] = j;
                } else {
                    pos[i][id[s[i][j]]][0] = j;
                }
            }
        }
        for (int i = 0; i < 52; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                il[i][j] = 1, adj[i][j].clear();
                for (int k = 0; k < n; ++k) {
                    il[i][j] &= (pos[k][i][(j >> k) & 1] > 0);
                }
            }
        }
        for (int i = 0; i < 52; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                if (il[i][j] == 0) continue;
                for (int k = 0; k < 52; ++k) {
                    if (i == k) {
                        if (j == 0 && il[k][(1 << n) - 1]) {
                            adj[i][j].emplace_back(k, (1 << n) - 1);
                            ++deg[k][(1 << n) - 1];
                        }
                        continue;
                    }
                    int64 S = 0;
                    for (int p = 0; p < n; ++p) {
                        if (pos[p][k][0] > pos[p][i][(j >> p) & 1]) continue;
                        if (pos[p][k][1] > pos[p][i][(j >> p) & 1]) {
                            S |= (1 << p);
                            continue;
                        }
                        S = -1;
                        break;
                    }
                    if (~S) adj[i][j].emplace_back(k, S), ++deg[k][S];
                }
            }
        }
        topo();
    }
    return 0;
}