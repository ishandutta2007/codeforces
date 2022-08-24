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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

struct Segment {
    int v44, v47, v74, v77;
    Segment() {}
    Segment(int v44, int v47, int v74, int v77) : v44(v44), v47(v47), v74(v74), v77(v77) {}
    Segment operator!() const {
        return Segment(v77, v74, v47, v44);
    }
};
ostream &operator<<(ostream &os, const Segment &a) {
    os << "(" << a.v44 << ", " << a.v47 << ", " << a.v74 << ", " << a.v77 << ")";
    return os;
}
Segment operator*(const Segment &a, const Segment &b) {
    return Segment(
        a.v44 + b.v44, 
        max(a.v47 + b.v77, a.v44 + b.v47), 
        max(a.v74 + b.v44, a.v77 + b.v74), 
        a.v77 + b.v77
    );
}

#define MAX 2200010

int N, M;
char A[MAX];

int segN;
Segment seg[MAX];
int sw[MAX];

void segPro(int a) {
    seg[a] = (sw[a << 1] ? !seg[a << 1] : seg[a << 1]) * (sw[a << 1 | 1] ? !seg[a << 1 | 1] : seg[a << 1 | 1]);
}
void segSw(int a, int b) {
    int c, d;
    for (c = a += segN, d = b += segN; a <= b; a >>= 1, b >>= 1, c >>= 1, d >>= 1) {
        if (c != a) segPro(c);
        if (d != b) segPro(d);
        if ( a & 1) { sw[a] ^= 1; ++a; }
        if (~b & 1) { sw[b] ^= 1; --b; }
    }
    for (; c; c >>= 1, d >>= 1) {
        segPro(c);
        segPro(d);
    }
}

int main() {
    int i, a;
    char typ[110];
    
    for (; ~scanf("%d%d", &N, &M); ) {
        scanf("%s", A);
        for (segN = 1; segN < N; segN <<= 1);
        for (i = 0; i < segN; ++i) {
            seg[segN + i] = (i < N) ? (A[i] == '4') ? Segment(1, 1, 1, 0) : Segment(0, 1, 1, 1) : Segment(0, 0, 0, 0);
            sw[segN + i] = 0;
        }
        for (a = segN; --a; ) {
            segPro(a);
            sw[a] = 0;
        }
        for (; M--; ) {
//cout<<"seg : ";pv(seg+1,seg+(segN<<1));
//cout<<"sw : ";pv(sw+1,sw+(segN<<1));
            scanf("%s", typ);
            if (typ[0] == 's') {
                int a = in() - 1;
                int b = in() - 1;
                segSw(a, b);
            } else {
                Segment res = sw[1] ? !seg[1] : seg[1];
                printf("%d\n", res.v47);
            }
        }
    }
    
    return 0;
}