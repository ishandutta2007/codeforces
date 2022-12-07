#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int P = (479<<21) + 1;
const int G = 3;

int quick_mod(int x, int k, int MOD) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
}

void change(int *y, int len) {
    int i, j, k;
    for(i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        //i<j
        //i+1j+1,ij
        k = len / 2;
        while(j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}

void ntt(int *y, int len, int on) {
    change(y, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1) {
        id++;
        int wn = quick_mod(G, (P - 1) / (1<<id), P);
        for(int j = 0; j < len; j += h) {
            int w = 1;
            for(int k = j; k < j + h / 2; k++) {
                int u = y[k] % P;
                int t = 1LL * w * y[k + h / 2] % P;
                y[k] = (u + t) % P;
                y[k + h / 2] = ((u - t) % P + P) % P;
                w = 1LL * w * wn % P;
            }
        }
    }
    if(on == -1) {
        for (int i = 1; i < len / 2; i++)
            swap(y[i], y[len - i]);
        int inv = quick_mod(len, P - 2, P);
        for(int i = 0; i < len; i++)
            y[i] = 1LL * y[i] * inv % P;
    }
}

const int N = 1000005;
int n, k, ans[N], x[N], Max;
int x1[N * 4], x2[N * 4];

void gao(int *a, int la, int *b, int lb) {
    int len = 1;
    while (len * 2 <= (la + lb) * 2) len *= 2;
    for (int i = 0; i < len; i++) x1[i] = i <= la ? a[i] : 0;
    for (int i = 0; i < len; i++) x2[i] = i <= lb ? b[i] : 0;
    ntt(x1, len, 1); ntt(x2, len, 1);
    for (int i = 0; i < len; i++) x1[i] = 1LL * x1[i] * x2[i] % P;
    ntt(x1, len, -1);
    for (int i = 0; i <= la + lb; i++) a[i] = (x1[i] > 0);
}

int main() {
    scanf("%d%d", &n, &k);
    int a;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        Max = max(Max, a);
        x[a] = 1;
    }
    int la = 0, lx = Max;
    ans[0] = 1;
    while (k) {
        if (k&1) {
            gao(ans, la, x, lx);
            la += lx;
        }
        k >>= 1;
        if (k) gao(x, lx, x, lx);
        lx += lx;
    }
    for (int i = 0; i <= la; i++)
        if (ans[i]) printf("%d ", i);
    printf("\n");
    return 0;
}