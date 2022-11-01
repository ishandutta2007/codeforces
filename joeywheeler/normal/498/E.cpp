#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

struct mat {
    int f[1<<7][1<<7];

    mat() {
        memset(f,0,sizeof f);
    }
};

mat calctrans(int h) {
    mat res;
    FO(m,0,1<<h) {
        FO(ver,0,1<<h) {
            FO(hor,0,1<<(h-1)) {
                bool bad = false;
                FO(i,0,h) {
                    int lower = 0;
                    if (i == 0) lower = 1;
                    else lower = hor & (1<<(i-1));
                    int upper = 0;
                    if (i == h-1) upper = 1;
                    else upper = hor & (1<<i);
                    int left = m & (1<<i);
                    int right = ver & (1<<i);
                    if (lower && upper && left && right) {
                        bad = true;
                        break;
                    }
                }
                if (!bad) res.f[m][ver]++;
            }
        }
    }
    return res;
}

mat step1(int h) {
    mat res;
    FO(m,0,1<<h) {
        res.f[m][m|(1<<h)] = 1;
    }
    return res;
}

mat mul(mat a, mat b) {
    mat r;
    unsigned long long MOD2 = MOD * 1ll * MOD;
    FO(i,0,1<<7) FO(j,0,1<<7) {
        unsigned long long val = 0;
        FO(k,0,1<<7) {
            val += a.f[i][k] * 1ll * b.f[k][j];
            if (val >= MOD2) val -= MOD2;
        }
        r.f[i][j] = val % MOD;
    }
    return r;
}

mat pow(mat a, int b) {
    mat r;
    FO(i,0,1<<7) r.f[i][i] = 1;
    while (b) {
        if (b&1) r = mul(r, a);
        a = mul(a,a);
        b /= 2;
    }
    return r;
}

int main() {
    mat r;
    FO(i,0,1<<7) r.f[i][i] = 1;
    FO(i,1,8) {
        int w;
        scanf("%d", &w);
        r = mul(r, pow(calctrans(i),w));
        if (i != 7) r = mul(r, step1(i));
    }
    printf("%d\n", r.f[1][(1<<7)-1]);
}