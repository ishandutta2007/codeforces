// Hydro submission #62596cd9cc64917dc466956f@1650027738354
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long

inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

#define N 1000010
#define M 100010

int n, vs[N], pr[N], cp = 0, sp[N];
bool res[N];
ULL f[N], hat[N];

ULL ran() {
    ULL res = 0;
    for (int i = 0; i < 63; i ++) {
        res = (res << 1) + (rand() & 1);
    }
    return res;
}

void get_prime() {
    for (int i = 2; i < N; i ++) {
        if (!vs[i]) {
            pr[++ cp] = i;
            sp[i] = i;
            // cout << i << endl;
            hat[i] = ran();
        }
        for (int j = 1; j <= cp; j ++) {
            if (i * pr[j] >= N) break;
            vs[i * pr[j]] = 1;
            sp[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

ULL Div(int x) {
    if (x == 1) return 0;
    else return hat[sp[x]] ^ Div(x / sp[x]);
}

int F() {
    ULL k = 0;
    for (int i = 1; i <= n; i ++) {
        k ^= f[i];
    }
    if (k == 0) return 0;
    for (int i = 1; i <= n; i ++) {
        if (k == f[i]) {
            res[i] = true;
            return 1;
        }
    }
    map<ULL, int> mp;
    for (int i = 1; i <= n; i ++) {
        mp[f[i]] = i;
    }
    for (int i = 1; i <= n; i ++) {
        ULL t = k ^ f[i];
        if (mp[t] != 0) {
            res[i] = true;
            res[mp[t]] = true;
            return 2;
        }
    }
    res[2] = res[n / 2] = res[n] = true;
    return 3;
}

signed main() {
    srand(time(0));
    get_prime();
    n = read();
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i - 1] ^ Div(i);
    }
    printf("%d\n", n - F());
    for (int i = 1; i <= n; i ++) {
        if (!res[i]) printf("%d ", i);
    }
    puts("");
    return 0;
}