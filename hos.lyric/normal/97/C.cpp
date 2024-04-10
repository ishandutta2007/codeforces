//  Yandex.Algorithm 2011 Finals

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

const double INF = 1e+10;

int N;
double P[210];
int V, M;
int A[20010], B[20010];
double C[20010];
double d[210][210];

int main() {
    int h, i;
    int u, v;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i <= N; ++i) {
            scanf("%lf", &P[i]);
        }
        V = N * 2 + 1;
        for (u = 0; u < V; ++u) {
            for (i = 0; i <= N; ++i) {
                v = u + i - (N - i);
                if (0 <= v && v < V) {
                    A[M] = u;
                    B[M] = v;
                    C[M] = -P[i];
                    ++M;
                }
            }
        }
        memset(d, 0, sizeof(d));
        for (h = 0; h <= V; ++h) {
            for (u = 0; u < V; ++u) {
                d[h][u] = INF;
            }
        }
        d[0][N] = 0;
        for (h = 0; h < V; ++h) {
//cout<<"d[h] : ";pv(d[h],d[h]+V);
            for (i = 0; i < M; ++i) {
                chmin(d[h + 1][B[i]], d[h][A[i]] + C[i]);
            }
        }
        double ans = INF;
        for (u = 0; u < V; ++u) {
            double dai = -INF;
            for (h = 0; h < V; ++h) if (d[h][u] < INF) {
                chmax(dai, (d[V][u] - d[h][u]) / (V - h));
            }
//cout<<"u = "<<u<<", dai = "<<dai<<endl;
            chmin(ans, dai);
        }
        printf("%.10f\n", -ans);
    }
    
    return 0;
}