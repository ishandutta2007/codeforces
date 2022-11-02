#include <bits/stdc++.h>
using namespace std;

const int C = 15;

bool in[C];

int n, sz, tick, cct, cnt;
int low[C], en[C], stk[C];
int adj[C][C];

bool na[C][C];

vector<int> ccf[C];

void tarjan(int u) {
    low[u] = en[u] = tick++;
    in[u] = 1;
    stk[sz++] = u;
    int i, j, k;
    for (i = 0; i < n; ++i) {
        if (!adj[u][i]) continue;
        if (en[i] == -1) {
            tarjan(i);
            low[u] = min(low[u], low[i]);
        } else if (in[i]) {
            low[u] = min(low[u], en[i]);
        }
    }
    if (low[u] == en[u]) {
        while (1) {
            int cu = stk[sz - 1];
            ccf[cct].push_back(cu);
            in[cu] = 0;
            --sz;
            if (cu == u) break;
        }
        ++cct;
    }
}

int occ[100][3][500], he[C];
int main() {
    int i, j, k, l;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &adj[i][j]);
        }
    }
    sz = 0;
    memset(en, -1, sizeof(en));
    for (i = 0; i < n; ++i) {
        if (en[i] == -1) {
            memset(in, 0, sizeof(in));
            tarjan(i);
        }
    }
    for (i = 0; i < cct; ++i) {
        if (cct - 1 - i > i) swap(ccf[i], ccf[cct - 1 - i]);
    }
    for (i = 0; i < cct; ++i) {
        for (j = i + 1; j < cct; ++j) {
            for (k = 0; k < (int)ccf[i].size(); ++k) {
                for (l = 0; l < (int)ccf[j].size(); ++l) {
                    if (adj[ccf[i][k]][ccf[j][l]]) {
                        na[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    for (i = 0; i < cct; ++i) {
        if (i) {
            he[i] = he[i - 1] - 3;
        } else {
            he[i] = cct * 3;
        }
        for (j = 0; j < (int)ccf[i].size(); ++j) {
            occ[he[i] + 1][0][j] = ccf[i][j] + 1;
        }
        for (k = 0; k < 3; ++k) {
            for (j = 0; j < n + 5; ++j) {
                occ[he[i]][k][j] = -1;
            }
        }
    }
    cnt = n + 5;
    for (i = 0; i < cct; ++i) {
        for (j = 1; j < cct; ++j) {
            if (!na[i][j]) continue;
            for (k = 0; k < cct; ++k) {
                for (l = 0; l < 3; ++l) {
                    occ[he[k]][l][cnt] = -1;
                    occ[he[k]][l][cnt + 1] = -1;
                    occ[he[k]][l][cnt + 2] = -1;
                }
            }
            occ[he[i]][0][cnt] = 0;
            for (k = i + 1; k < j; ++k) {
                occ[he[k]][0][cnt] = 0;
                for (l = 1; l < 3; ++l) {
                    occ[he[k] + l][1][cnt] = -1;
                    occ[he[k] + l][0][cnt - 1] = -1;
                    occ[he[k] + l][0][cnt + 1] = -1;
                }
            }
            cnt += 3;
        }
    }
    printf("%d 3 %d\n", cnt + 1, cct * 3 + 2);
    for (i = cct * 3 + 1; i >= 0; --i) {
        for (j = 0; j < 3; ++j) {
            for (k = 0; k <= cnt; ++k) {
                if (occ[i][j][k] == -1) {
                    printf("#");
                } else if (occ[i][j][k] == 0) {
                    printf(".");
                } else {
                    printf("%d", occ[i][j][k]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}