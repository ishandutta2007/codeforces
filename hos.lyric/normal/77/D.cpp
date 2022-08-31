//  Codeforces Beta Round #69

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

char VERT[] = 
"........."
"....O...."
"..O...O.."
"..O.O.O.."
"O.O...O.O"
"O.O.O.O.O"
"O.OO.OO.O"
;

char HORI[] = 
"........."
"....O...."
"O.......O"
"O...O...O"
"O.O...O.O"
"O.O.O.O.O"
"OOO...OOO"
;

const Int MO = 1000000007;

int M, N;
char S[1010][1010];
map<int,int> sV, sH;
bool isV[310][310], isH[310][310];
Int dp1[310], dp2[310];
Int dp[310];
Int DP[310];

Int calc1(int y) {
    if (M % 2 != 0) {
        return 0;
    }
    int x;
    for (x = 0; x < M; ++x) {
        if (!isV[x][y]) return 0;
    }
    return 1;
}

Int calc2(int y) {
    int x;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (x = 1; x <= M; ++x) {
        if (x >= 1) {
            if (isH[x - 1][y] && isH[x - 1][y + 1]) {
                dp[x] += dp[x - 1];
            }
        }
        if (x >= 2) {
            if (isV[x - 2][y] && isV[x - 2][y + 1] && isV[x - 1][y] && isV[x - 1][y + 1]) {
                dp[x] += dp[x - 2];
            }
        }
        dp[x] %= MO;
    }
    Int ret = dp[M];
    
    //  all vertical
    bool allV = 1;
    if (M % 2 != 0) allV = 0;
    for (x = 0; x < M; ++x) {
        if (!isV[x][y]) allV = 0;
        if (!isV[x][y + 1]) allV = 0;
    }
    if (allV) {
        ret += MO - 1;
        ret %= MO;
    }
    
    return ret;
}

int main() {
    int e, f;
    int s;
    int x, y;
    
//for(s=0;s<7;++s){for(e=0;e<3;++e){for(f=0;f<3;++f)putchar(VERT[s*9+e*3+f]);cout<<endl;}cout<<endl;}
//for(s=0;s<7;++s){for(e=0;e<3;++e){for(f=0;f<3;++f)putchar(HORI[s*9+e*3+f]);cout<<endl;}cout<<endl;}
    for (s = 0; s < 7; ++s) {
        int u = 0;
        for (e = 0; e < 3; ++e) for (f = 0; f < 3; ++f) {
            if (VERT[s * 9 + e * 3 + f] == 'O') {
                u |= 1 << e * 3 + f;
            }
        }
        sV[u] = s;
    }
    for (s = 0; s < 7; ++s) {
        int u = 0;
        for (e = 0; e < 3; ++e) for (f = 0; f < 3; ++f) {
            if (HORI[s * 9 + e * 3 + f] == 'O') {
                u |= 1 << e * 3 + f;
            }
        }
        sH[u] = s;
    }
    
    for (; ~scanf("%d%d", &M, &N); ) {
        for (e = 0; e < M * 4 + 1; ++e) {
            scanf("%s", S[e]);
        }
        memset(isV, 0, sizeof(isV));
        memset(isH, 0, sizeof(isH));
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            int u = 0;
            for (e = 0; e < 3; ++e) for (f = 0; f < 3; ++f) {
                if (S[x * 4 + 1 + e][y * 4 + 1 + f] == 'O') {
                    u |= 1 << e * 3 + f;
                }
            }
            isV[x][y] = sV.count(u);
            isH[x][y] = sH.count(u);
//if(sV.count(u))cout<<x<<" "<<y<<": "<<sV[u]<<endl;
//if(sH.count(u))cout<<x<<" "<<y<<": "<<sH[u]<<endl;
        }
//for(x=0;x<M;++x)pv(isV[x],isV[x]+N);cout<<endl;
//for(x=0;x<M;++x)pv(isH[x],isH[x]+N);cout<<endl;
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        memset(DP, 0, sizeof(DP));
        for (y = 0; y + 1 <= N; ++y) {
            dp1[y] = calc1(y);
        }
        for (y = 0; y + 2 <= N; ++y) {
            dp2[y] = calc2(y);
        }
//cout<<"dp1: ";pv(dp1,dp1+N);
//cout<<"dp2:  ";pv(dp2,dp2+N-1);
        DP[0] = 1;
        for (y = 1; y <= N; ++y) {
            if (y >= 1) {
                DP[y] += DP[y - 1] * dp1[y - 1];
            }
            if (y >= 2) {
                DP[y] += DP[y - 2] * dp2[y - 2];
            }
            DP[y] %= MO;
        }
        cout << DP[N] << endl;
//cerr<<"====="<<endl;
    }
    
    return 0;
}