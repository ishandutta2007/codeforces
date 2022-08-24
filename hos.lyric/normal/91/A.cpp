//  Codeforces Beta Round #75

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

const int L = 26;
int M, N;
char S[1000010], T[1000010];
int next[10010][30];

int main() {
    int l, i, j;
    
    for (; ~scanf("%s%s", S, T); ) {
        M = strlen(S);
        N = strlen(T);
        for (l = 0; l < L; ++l) {
            next[M][l] = M;
        }
        for (i = M; i--; ) {
            for (l = 0; l < L; ++l) {
                next[i][l] = (S[i] - 'a' == l) ? i : next[i + 1][l];
            }
//cout<<"next[i] : ";pv(next[i],next[i]+4);
        }
        int ans = 0;
        for (j = 0; j < N; ++j) {
            if (next[0][T[j] - 'a'] == M) {
                ans = -1;
                goto done;
            }
        }
        ans = 1;
        i = -1;
        for (j = 0; j < N; ++j) {
            ++i;
            i = next[i][T[j] - 'a'];
            if (i == M) {
                ++ans;
                i = next[0][T[j] - 'a'];
            }
        }
    done:;
        printf("%d\n", ans);
    }
    
    return 0;
}