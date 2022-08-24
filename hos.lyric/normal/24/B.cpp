//  Codeforces Beta Round #24
//  Problem B

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

int P[] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1, };
int T, N;
int V;
string S[1010];
map<string,int> tr;
int pts[1010];
vector<vint> cnt(1010, vint(60));

int main() {
    int i, u, um;
    string str;
    
    T = in();
    for (; T--; ) {
        N = in();
        for (i = 0; i < N; ++i) {
            cin >> str;
            if (!tr.count(str)) {
                S[V] = str;
                tr[str] = V;
                ++V;
            }
            u = tr[str];
            if (i < 10) pts[u] += P[i];
            ++cnt[u][i];
        }
    }
    um = 0;
    for (u = 0; u < V; ++u) {
        if (pts[um] < pts[u] || pts[um] == pts[u] && cnt[um] < cnt[u]) um = u;
    }
    cout << S[um] << endl;
    um = 0;
    for (u = 0; u < V; ++u) {
        if (cnt[um][0] < cnt[u][0] || cnt[um][0] == cnt[u][0] && (pts[um] < pts[u] || pts[um] == pts[u] && cnt[um] < cnt[u])) um = u;
    }
    cout << S[um] << endl;
    
    
    return 0;
}