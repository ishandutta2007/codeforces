#include <bits/stdc++.h>
using namespace std;

#define N 1111

int a[N];
int b[N];
int p[N];
bool found[N];
int n;
bool subok(int x, int y) {
    for (int v = 1; v <= n; v++) found[v] = false;
    for (int i = 0; i < n; i++) {
        if (i != x && i != y) {
            found[p[i] = a[i]] = true;
        }
    }
    p[x] = p[y] = -1;
    for (int v = 1; v <= n; v++) {
        if (!found[v]) {
            p[p[x] == -1 ? x : y] = v;
        }
    }
    for (int v = 1; v <= n; v++) found[v] = false;
    int ma = 0, mb = 0;
    for (int i = 0; i < n; i++) {
        if (found[p[i]]) return false;
        ma += p[i] == a[i];
        mb += p[i] == b[i];
    }
    return ma == n - 1 && mb == n - 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int ai = 0, aj = 0, bi = 0, bj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) ai = i, aj = j;
            if (b[i] == b[j]) bi = i, bj = j;
        }
    }
    if (subok(ai, ai) ||
        subok(ai, aj) ||
        subok(ai, bi) ||
        subok(ai, bj) ||
        subok(aj, ai) ||
        subok(aj, aj) ||
        subok(aj, bi) ||
        subok(aj, bj) ||
        subok(bi, ai) ||
        subok(bi, aj) ||
        subok(bi, bi) ||
        subok(bi, bj) ||
        subok(bj, ai) ||
        subok(bj, aj) ||
        subok(bj, bi) ||
        subok(bj, bj)) {
        for (int i = 0; i < n; i++) {
            printf("%d%c", p[i], " \n"[i == n - 1]);
        }
    }
}