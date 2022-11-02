#include <bits/stdc++.h>

const int N = 210000;
const int S = 300;
const int Q = N / S + 10;
const int C = 110;

int n, Cnt;
int a[N];
int Clo[Q][C], Go[Q][C], Size[Q][C], Pe[Q][C];

int Get(int k, int a) {
    if (Pe[k][a] == a) return a;
    return Pe[k][a] = Get(k, Pe[k][a]);
}

void Sec(int k, int a, int b) {
    int atmp = a;
    a = Go[k][a];
    int b2 = Go[k][b];
    Go[k][atmp] = -1;
    if (a == -1) return;
    if (b2 == -1) return Go[k][b] = a, Clo[k][a] = b, void(0);
    if (Size[k][a] > Size[k][b2]) std::swap(a, b2);
    Pe[k][a] = b2, Size[k][b2] += Size[k][a];
    Clo[k][b2] = b, Go[k][b] = b2;
}

void Rebuild(int k) {
    for (int i = 0; i < C; ++i) Size[k][i] = 1, Pe[k][i] = i, Clo[k][i] = i, Go[k][i] = i;
}

void Push(int k) {
    int l = k * S;
    int r = std::min(n, (k + 1) * S);
    for (int i = l; i < r; ++i) a[i] = Clo[k][Get(k, a[i])];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    Cnt = (n - 1) / S + 1;
    for (int i = 0; i < Cnt; ++i) Rebuild(i);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int l, r, x, y;
        scanf("%d %d %d %d", &l, &r, &x, &y);
        if (x == y) continue;
        --l;
        int bl = (l + S - 1) / S, br = r / S;
        for (int j = bl; j < br; ++j) Sec(j, x, y);
        int r2 = bl * S;
        if (l < r2) {
            Push(l / S);
            for (int i = l; i < std::min(r, r2); ++i) {
                if (a[i] == x) a[i] = y;
            }
            Rebuild(l / S);
        }
        int l2 = br * S;
        if (l2 < r && l <= l2) {
            Push(r / S);
            for (int i = l2; i < r; ++i) {
                if (a[i] == x) a[i] = y;
            }
            Rebuild(r / S);
        }
    }
    for (int i = 0; i < Cnt; ++i) Push(i);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    return 0;
}