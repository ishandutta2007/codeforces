//  Codeforces Beta Round 66

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

#define MAXN 1000010

int uf[MAXN];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

int N, M, K;
int C;

int main() {
    int i;
    int u, v;
    
    for (; ~scanf("%d%d%d", &N, &M, &K); ) {
        memset(uf, ~0, sizeof(uf));
        for (i = 0; i < M; ++i) {
            u = in() - 1;
            v = in() - 1;
            conn(u, v);
        }
        C = 0;
        priority_queue< int,vint,greater<int> > q;
        int sum = 0;
        for (u = 0; u < N; ++u) if (uf[u] < 0) {
            ++C;
            q.push(-uf[u]);
            sum += min(-uf[u], K);
        }
//cout<<"C = "<<C<<endl;
        int ans = 0;
        for (; ; ) {
            if (sum >= 2 * (C - 1)) {
                break;
            }
            int a = q.top(); q.pop(); sum -= min(a, K);
            int b = q.top(); q.pop(); sum -= min(b, K);
            q.push(a + b); sum += min(a + b, K);
//cout<<"pop "<<a<<" "<<b<<endl;
            --C;
            ++ans;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}