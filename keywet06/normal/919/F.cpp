#include <bits/stdc++.h>

const int S = 13131;

using int64 = unsigned long long;

struct Edge {
    int next;
    int to;
} edge[250005 * 64];

struct node {
    int a[9];
    int b[9];
    int64 hh;
    int typ;
} sit[250005];

int x[9], temp[9], temp2[9], ta[9], tb[9];
int tempsit[250005][9];
int head[250005];
int inr[250005];
int cnt = 1, tot, cct;
std::map<int64, int> M, nnum, used[250005];
std::queue<int> Q;
void init() { memset(head, -1, sizeof(head)), cnt = 1; }
void add(int l, int r) {
    edge[cnt].next = head[l];
    edge[cnt].to = r;
    head[l] = cnt++;
}
void dfs(int dep) {
    if (dep == 9) {
        memcpy(temp, x, sizeof(x));
        std::sort(temp + 1, temp + dep);
        int64 has = 1;
        for (int i = 1; i <= 8; i++) has = has * S + temp[i];
        if (!M[has]) {
            M[has] = 1, tot++;
            memcpy(tempsit[tot], temp, sizeof(temp));
        }
        return;
    }
    for (int i = 0; i <= 4; i++) x[dep] = i, dfs(dep + 1);
}
void judge() {
    for (int i = 1; i <= tot * tot; i++) {
        bool flag = 0;
        for (int j = 1; j <= 8; j++) {
            if (sit[i].a[j] != 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            sit[i].typ = 1, Q.push(i);
            continue;
        }
        flag = 0;
        for (int j = 1; j <= 8; j++) {
            if (sit[i].b[j] != 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            sit[i].typ = 2, Q.push(i);
            continue;
        }
    }
}
void make_sit() {
    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= tot; j++) {
            memcpy(sit[(i - 1) * tot + j].b, tempsit[j], sizeof(sit[j].a));
            memcpy(sit[(i - 1) * tot + j].a, tempsit[i], sizeof(sit[i].a));
            int64 has = 1;
            for (int k = 1; k <= 8; k++) {
                has = has * S + sit[(i - 1) * tot + j].a[k];
            }
            for (int k = 1; k <= 8; k++) {
                has = has * S + sit[(i - 1) * tot + j].b[k];
            }
            nnum[has] = (i - 1) * tot + j;
            sit[(i - 1) * tot + j].hh = has;
        }
    }
}
void add_edge() {
    for (int i = 1; i <= tot * tot; i++) {
        for (int j = 1; j <= 8; j++) {
            if (sit[i].a[j] == 0) continue;
            for (int k = 1; k <= 8; k++) {
                if (sit[i].b[k] == 0) continue;
                int t = (sit[i].a[j] + sit[i].b[k]) % 5;
                memcpy(temp, sit[i].b, sizeof(temp));
                memcpy(temp2, sit[i].a, sizeof(temp2));
                temp2[j] = t;
                int64 has = 1;
                std::sort(temp + 1, temp + 9), std::sort(temp2 + 1, temp2 + 9);
                for (int p = 1; p <= 8; p++) has = has * S + temp[p];
                for (int p = 1; p <= 8; p++) has = has * S + temp2[p];
                if (used[i][has]) continue;
                used[i][has] = 1, add(nnum[has], i), inr[i]++;
            }
        }
    }
}
void bfs() {
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int to = edge[i].to;
            if (!inr[to]) continue;
            if (sit[u].typ == 2) {
                sit[to].typ = 1, inr[to] = 0, Q.push(to);
            } else {
                inr[to]--;
                if (!inr[to] && !sit[to].typ) sit[to].typ = 2, Q.push(to);
            }
        }
    }
}
int main() {
    init(), dfs(1), make_sit(), judge(), add_edge(), bfs();
    int T;
    scanf("%d", &T);
    while (T--) {
        int ty;
        scanf("%d", &ty);
        for (int i = 1; i <= 8; i++) scanf("%d", &ta[i]);
        for (int i = 1; i <= 8; i++) scanf("%d", &tb[i]);
        std::sort(ta + 1, ta + 9), std::sort(tb + 1, tb + 9);
        int64 has = 1;
        if (ty) {
            for (int i = 1; i <= 8; i++) has = has * S + tb[i];
            for (int i = 1; i <= 8; i++) has = has * S + ta[i];
            int t = nnum[has], i = sit[t].typ;
            printf("%s\n", !i ? "Deal" : (i == 1 ? "Bob" : "Alice"));
        } else {
            for (int i = 1; i <= 8; i++) has = has * S + ta[i];
            for (int i = 1; i <= 8; i++) has = has * S + tb[i];
            int t = nnum[has], i = sit[t].typ;
            printf("%s\n", !i ? "Deal" : (i == 1 ? "Alice" : "Bob"));
        }
    }
    return 0;
}