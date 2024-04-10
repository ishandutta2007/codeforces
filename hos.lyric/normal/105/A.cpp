//  Codeforces Beta Round #81

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

int N, M;
double K;
int KK;

string S[110];
int P[110];

int psLen;
pair<string,int> ps[110];

int main() {
    int i;
    char buf[110];
    
    for (; ~scanf("%d%d%lf", &N, &M, &K); ) {
        KK = (int)(K * 100 + 0.5);
        for (i = 0; i < N; ++i) {
            scanf("%s", buf);
            S[i] = buf;
            P[i] = in();
        }
        for (i = N; i < N + M; ++i) {
            scanf("%s", buf);
            S[i] = buf;
            P[i] = 0;
        }
        for (i = 0; i < N + M; ++i) {
            P[i] = P[i] * KK / 100;
        }
        set<string> have;
        psLen = 0;
        for (i = 0; i < N + M; ++i) {
            if (i < N && P[i] < 100) {
                continue;
            }
            if (!have.insert(S[i]).second) {
                continue;
            }
            ps[psLen++] = mp(S[i], P[i]);
        }
        sort(ps, ps + psLen);
        printf("%d\n", psLen);
        for (i = 0; i < psLen; ++i) {
            printf("%s %d\n", ps[i].first.c_str(), ps[i].second);
        }
    }
    
    return 0;
}