//  Codeforces Beta Round #88

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

int N;
char A[5010][5010];
int us[5010];

void answer(int u, int v, int w) {
//cout<<A[u][v]<<" "<<A[v][w]<<" "<<A[w][u]<<endl;
    printf("%d %d %d\n", u + 1, v + 1, w + 1);
}

int main() {
    int i, j, k;
    int u, v;
    
    for (; ~scanf("%d", &N); ) {
        for (u = 0; u < N; ++u) {
            scanf("%s", A[u]);
        }
        for (u = 0; u < N; ++u) {
            us[u] = u;
            for (i = u; i > 0; --i) {
                if (A[us[i - 1]][us[i]] == '0') {
                    swap(us[i - 1], us[i]);
                } else {
                    break;
                }
            }
        }
//cout<<"us : ";pv(us,us+N);
        for (i = 0; i < N; ++i) for (j = i + 1; j < N; ++j) {
            if (A[us[i]][us[j]] == '0') {
                for (k = i + 1; ; ++k) {
                    if (A[us[k]][us[j]] == '1') {
                        answer(us[i], us[k], us[j]);
                        goto found;
                    }
                }
            }
        }
        puts("-1");
    found:;
    }
    
    return 0;
}