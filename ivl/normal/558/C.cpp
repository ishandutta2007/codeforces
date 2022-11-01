#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)

using namespace std;

const int oo = (int)1e9;

int n;
int a[100005];

int D(int x, int y){
    int R = 0;
    while (__builtin_popcount(x) > __builtin_popcount(y)) x >>= 1, ++R;
    if (y == 0) return R;
    int c1 = 0;
    while (!(x & 1)) ++c1, x >>= 1;
    while (!(y & 1)) --c1, y >>= 1;
    if (y != x) return oo;
    return R + abs(c1);
}

int main(){
    scanf("%d", &n);
    REP(n,i) scanf("%d", a + i);
    int R = oo;
    REP(1<<17,i){
        int cR = 0;
        REP(n,j){
            cR += D(a[j], i);
            if (cR >= R) break;
        } R = min(R, cR);
    } printf("%d\n", R);
    return 0;
}