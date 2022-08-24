//  Codeforces Beta Round #58 (B)

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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const int W = 26;
const int INF = 1001001001;

int qry;
int L, M;
char S[1000010], T[1000010];
int lef[30][200010], rig[30][200010];

int main() {
    int j, jj;
    int c;
    
    scanf("%d%d", &qry, &L);
    scanf("%s", S);
    for (c = 0; c < W; ++c) {
        for (j = 0; j < L; ++j) {
            if (S[j] - 'a' == c) {
                lef[c][j] = j;
            } else {
                lef[c][j] = (j == 0) ? -INF : lef[c][j - 1];
            }
        }
        for (j = L; j--; ) {
            if (S[j] - 'a' == c) {
                rig[c][j] = j;
            } else {
                rig[c][j] = (j == L - 1) ? +INF : rig[c][j + 1];
            }
        }
    }
    for (; qry--; ) {
        scanf("%s", T);
        M = strlen(T);
        Int ans = 0, tmp;
        for (j = 0; j < M; ++j) {
            c = T[j] - 'a';
            jj = min(j, L - 1);
            tmp = min(abs(j - lef[c][jj]), abs(j - rig[c][jj]));
            if (tmp > INF / 2) tmp = M;
            ans += tmp;
        }
        cout << ans << endl;
    }
    
    return 0;
}