//  Codeforces Beta Round #23
//  Problem C

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

int N, M;
pair<pint,int> ps[300010];

int ans[300010];

int main() {
    int i;
    
    for (int TC = in(); TC--; ) {
        N = in();
        M = N * 2 - 1;
        for (i = 0; i < M; ++i) {
            ps[i].first.first = in();
            ps[i].first.second = in();
            ps[i].second = i;
        }
        sort(ps, ps + M);
        for (i = 0; i < M - 1; i += 2) {
            ans[i / 2] = ps[(ps[i + 0].first.second < ps[i + 1].first.second) ? (i + 1) : (i + 0)].second;
        }
        ans[N - 1] = ps[M - 1].second;
        sort(ans, ans + N);
        puts("YES");
        for (i = 0; i < N; ++i) {
            if (i) putchar(' ');
            printf("%d", ans[i] + 1);
        }
        puts("");
    }
    
    return 0;
}