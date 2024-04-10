#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;

int gl(ll x) {
    int res = 0;
    while (x) {
        res++;
        x /= 2;
    }
    return res-1;
}

ull shf[63];

int main() {
    int q; scanf("%d", &q);
    fo(i,0,q) {
        int t;
        scanf("%d", &t);
        if (t == 1 || t == 2) {
            ll x, k; scanf("%lld %lld", &x, &k);
            int lvl = gl(x);
            ull lvs = 1ull << lvl;
            ull shk = ((k % lvs) + lvs) % lvs;
            if (t == 1) {
                shf[lvl] = (shf[lvl] + shk) % lvs;
            } else {
                fo(i,lvl,63) {
                    shf[i] = (shf[i] + shk) % lvs;
                    shk = shk << 1;
                    lvs = lvs << 1;
                }
            }
            //fo(i,0,4) printf("shf[%d]=%llu\n", i, shf[i]);
        } else {
            ll x;
            scanf("%lld", &x);
            int lvl = gl(x);
            ull lvs = (1ull<<lvl);
            ull ind = (x + shf[lvl]) % lvs;
            while (lvl >= 0) {
                printf("%lld ", (ind + lvs - shf[lvl]) % lvs + lvs);
                lvl--;
                lvs >>= 1;
                ind >>= 1;
            }
            printf("\n");
        }
    }
}