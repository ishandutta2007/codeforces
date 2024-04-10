#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    ll k;
    int a, b;
    scanf("%lld %d %d", &k, &a, &b);
    -- a, -- b;
    int A[3][3], B[3][3];
    rep(i, 3) rep(j, 3) scanf("%d", &A[i][j]), -- A[i][j];
    rep(i, 3) rep(j, 3) scanf("%d", &B[i][j]), -- B[i][j];
    int beats[3][3];
    memset(beats, 0, sizeof(beats));
    beats[0][2] = beats[1][0] = beats[2][1] = 1;
    int cyc = 2520;
    auto nex = [&] (int &sa, int &sb) {
        sa += beats[a][b];
        sb += beats[b][a];
        int na = A[a][b];
        int nb = B[a][b];
        a = na;
        b = nb;
    };
    int ia = 0, ib = 0;
    rep(i, k % cyc) nex(ia, ib);
    int oa = 0, ob = 0;
    rep(i, cyc) nex(oa, ob);
    printf("%lld %lld\n", ia + oa * (k / cyc), ib + ob * (k / cyc));
    return 0;
}