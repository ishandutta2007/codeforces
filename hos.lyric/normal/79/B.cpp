//  Codeforces Beta Round #71

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

#define MAX 100010

string CROPS[] = { "Carrots", "Kiwis", "Grapes", };

int M, N, K, Q;
int sum[MAX];
vint ys[MAX];

int main() {
    int x, y;
    
    for (; ~scanf("%d%d%d%d", &M, &N, &K, &Q); ) {
        for (x = 0; x < M; ++x) {
            ys[x].clear();
        }
        for (; K--; ) {
            x = in() - 1;
            y = in() - 1;
            ys[x].push_back(y);
        }
        for (x = 0; x < M; ++x) {
            sort(ys[x].begin(), ys[x].end());
            sum[x + 1] = sum[x] + ys[x].size();
        }
        for (; Q--; ) {
            x = in() - 1;
            y = in() - 1;
            uint i = lower_bound(ys[x].begin(), ys[x].end(), y) - ys[x].begin();
            if (i < ys[x].size() && ys[x][i] == y) {
                puts("Waste");
            } else {
                Int ans = x * (Int)N + y - sum[x] - i;
//cout<<x<<" "<<y<<" : "<<ans<<endl;
                ans %= 3;
                puts(CROPS[ans].c_str());
            }
        }
    }
    
    return 0;
}