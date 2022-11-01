#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define M 10000005
#define MOD 1000000007

using namespace std;

int n;
int c[M];
int f[M];
int lp[M];
int pw[500005];
int sqf[M];

int main() {
    scanf("%d", &n);
    pw[0] = 1;
    FO(i,1,500005) {
        pw[i] = pw[i-1]*2;
        if (pw[i] >= MOD) pw[i] -= MOD;
    }
    FO(i,0,n) {
        int x; scanf("%d", &x);
        c[x]++;
    }
    FO(i,2,M) if (lp[i] == 0) {
        for (int j = i; j < M; j += i) if (lp[j] == 0) lp[j] = i;
    }
    sqf[1] = 1;
    FO(i,2,M) {
        if (lp[i] != lp[i/lp[i]] && sqf[i/lp[i]]) sqf[i] = -1 * sqf[i/lp[i]];
    }
    FO(i,1,M) if (sqf[i]) {
        int v = 0;
        for (int j = i; j < M; j += i) v += c[j];
        f[i] = pw[v]-1;
    }
    for (int i = M-1; i >= 1; i--) if (sqf[i]) {
        for (int j = 2*i; j < M; j += i) {
            f[i] -= f[j];
            if (f[i] < 0) f[i] += MOD;
        }
    }
    f[1] = 0;
    int res = 0;
    FO(i,1,M) if (sqf[i]) {
        int s0 = 0, s1 = 0;
        for (int j = i; j < M; j += i) {
            s0 += f[j];
            s1 += c[j];
            if (s0 >= MOD) s0 -= MOD;
            if (s1 >= MOD) s1 -= MOD;
        }
        long long v = sqf[i] * s0 * 1ll * s1;
        v %= MOD;
        v += MOD;
        res = (res+v)%MOD;
    }
    printf("%d\n", res);
}