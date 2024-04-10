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

void Out(Int x) {
    if (x >= 10) Out(x / 10);
    putchar('0' + x % 10);
}

Int N;
int Q;
Int MO;

Int mul(Int a, Int b) {
    a %= MO; b %= MO;
    return a * b % MO;
}
Int mulDiv2(Int a, Int b) {
    a %= MO; b %= MO;
    if (a % 2 == 0) a /= 2;
    else b /= 2;
    return a * b % MO;
}
Int calc(Int u, Int p, Int m) {
    chmin(u, N);
    if (u < p) return 0;
    Int k = (u - p) / m;
    return (mul(mulDiv2(k, k + 1), m) + mul(k + 1, p)) % MO;
}
Int calc(Int u, Int v, Int p, Int m) {
    Int ret = 0;
    ret += calc(v, p, m);
    ret -= calc(u - 1, p, m);
//cout<<"calc "<<u<<" "<<v<<" "<<p<<" "<<m<<" : "<<ret<<endl;
    ret %= MO;
    return ret;
}

Int solve(Int l, Int r, Int u, Int v, Int a, Int b, Int p, Int m) {
    chmax(l, a); chmin(r, b);
    if (l > r) return 0;
    Int ret = 0;
    if (l == a && r == b) {
        ret += calc(u, v, p, m);
    } else {
        Int odd = (b - a + 1 + 1) / 2;
        ret += solve(l, r, u, v, a, a + odd - 1, p, m * 2);
        ret += solve(l, r, u, v, a + odd, b, p + m, m * 2);
    }
    ret %= MO;
    return ret;
}

int main() {
    int q;
    Int l, r, u, v;
    
    for (; cin >> N >> Q >> MO; ) {
        for (q = 0; q < Q; ++q) {
            l = In();
            r = In();
            u = In();
            v = In();
            Int res = solve(l, r, u, v, 1, N, 1, 1);
            res %= MO; res += MO; res %= MO;
            Out(res);
            puts("");
        }
    }
    
    return 0;
}