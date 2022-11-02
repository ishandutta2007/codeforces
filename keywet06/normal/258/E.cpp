#include <bits/stdc++.h>
using namespace std;

struct event {
    int X, L, R, Flag;
};

bool operator<(event A, event B) { return A.X < B.X; }

int cnt;
vector<int> G[100000];
int pa[100000], be[100000], en[100000];
int le[262144], ri[262144], de[262144], su[262144];

void dfs(int X, int Last) {
    pa[cnt] = X;
    be[X] = cnt++;
    for (int i = 0; i < G[X].size(); ++i)
        if (G[X][i] != Last) dfs(G[X][i], X);
    en[X] = cnt - 1;
}

void build(int P, int L, int R) {
    le[P] = L;
    ri[P] = R;
    if (L < R) {
        int Mid = (L + R) / 2;
        build(P * 2, L, Mid);
        build(P * 2 + 1, Mid + 1, R);
    }
}

void add(int P, int L, int R, int D) {
    if (le[P] == L && ri[P] == R)
        de[P] += D;
    else {
        int Mid = (le[P] + ri[P]) / 2;
        if (R <= Mid)
            add(P * 2, L, R, D);
        else if (L > Mid)
            add(P * 2 + 1, L, R, D);
        else {
            add(P * 2, L, Mid, D);
            add(P * 2 + 1, Mid + 1, R, D);
        }
    }
    su[P] = de[P] ? (ri[P] - le[P] + 1) : 0;
    if (!su[P] && le[P] < ri[P]) su[P] = su[P * 2] + su[P * 2 + 1];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i < N; ++i) {
        int X, Y;
        scanf("%d %d", &X, &Y), --X, --Y;
        G[X].push_back(Y);
        G[Y].push_back(X);
    }
    cnt = 0;
    dfs(0, -1);
    int Total = 0;
    event E[800000];
    for (int i = 0; i < M; ++i) {
        int X, Y;
        scanf("%d%d", &X, &Y), --X, --Y;
        int L0 = be[X], R0 = en[X];
        int L1 = be[Y], R1 = en[Y];
        E[Total++] = (event){L0, L0, R0, 1};
        E[Total++] = (event){R0 + 1, L0, R0, -1};
        E[Total++] = (event){L0, L1, R1, 1};
        E[Total++] = (event){R0 + 1, L1, R1, -1};
        E[Total++] = (event){L1, L0, R0, 1};
        E[Total++] = (event){R1 + 1, L0, R0, -1};
        E[Total++] = (event){L1, L1, R1, 1};
        E[Total++] = (event){R1 + 1, L1, R1, -1};
    }
    sort(E, E + Total);
    build(1, 0, N - 1);
    memset(de, 0, sizeof(de));
    memset(su, 0, sizeof(su));
    static int ans[100000];
    for (int i = 0, j = 0; i < N; ++i) {
        while (j < Total && E[j].X == i) {
            add(1, E[j].L, E[j].R, E[j].Flag), ++j;
        }
        ans[pa[i]] = su[1] ? (su[1] - 1) : 0;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d", ans[i]);
        putchar((i + 1 == N) ? '\n' : ' ');
    }
    return 0;
}