#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 4005;
const int MAXK = 805;
const llint INF = 1000000000000000LL;

llint n, k, curr;
llint c[MAXN] [MAXN], s[MAXN] [MAXN], dp[MAXN] [MAXK];

inline bool is( char c ) { return c >= '0' && c <= '9'; }

inline int read_int( ) {
    int num;
    char c;
    while( !is( c = getchar( ) ) );
    num = c - '0';
    while( is( c = getchar( ) ) ) num = num * 10 + c - '0';
    return num;
}

llint cost (int x, int y) {
    return (s[y] [y] - s[x-1] [y] - s[y] [x-1] + s[x-1] [x-1]) / 2;
}

void calc (int lef, int rig, int p_lef, int p_rig) {
    if (lef > rig) return;
    int mid = (lef + rig) / 2;
    llint sol = INF, p;
    for (int i=min(mid, p_rig); i>=p_lef; i--) {
        llint res = dp[i-1] [curr-1] + cost(i, mid);
        if (res < sol) {
            sol = res;
            p = i;
        }
    }
    dp[mid] [curr] = sol;
    calc(lef, mid-1, p_lef, p);
    calc(mid+1, rig, p, p_rig);
}

int main () {
    n = read_int();
    k = read_int();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            c[i] [j] = read_int();
            s[i] [j] = c[i] [j] + s[i-1] [j] + s[i] [j-1] - s[i-1] [j-1];
        }
    }
    dp[0] [1] = INF;
    for (int i=1; i<=n; i++) {
        dp[i] [1] = cost(1, i);
    }
    for (curr = 2; curr <= k; curr++) {
        calc(curr, n, 1, n);
    }
    cout << dp[n] [k];
    return 0;
}