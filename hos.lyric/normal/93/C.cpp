//  Codeforces Beta Round #76

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

const int BIG = 7;

typedef unsigned char uchar;

int N;
map< vint,pair<uchar,uchar> > mem;

pint calc(const vint &a) {
//cout<<"a : ";pv(a.begin(),a.end());
    int m = a.size();
    if (a.back() == N) {
        return mp(m, 0);
    }
    if (m + 1 >= BIG) {
        return mp(BIG, 0);
    }
    if (!mem.count(a)) {
        bool flgMem = (m <= 4);
        int k, y, z;
        vint aa = a;
        aa.push_back(0);
        int ret = BIG;
        int nxt = 0;
        set<int> made;
        for (k = 8; k >= 1; k /= 2) {
            for (y = 0; y <= m; ++y) for (z = 0; z <= m; ++z) {
                int b = aa[y] + k * aa[z];
                if (a.back() < b && b <= N) {
                    made.insert(b);
                }
            }
        }
        for (set<int>::iterator it = made.end(), bg = made.begin(); it-- != bg; ) {
            aa[m] = *it;
            int tmp = calc(aa).first;
            if (ret > tmp) {
                ret = tmp;
                nxt = *it;
            }
        }
        if (flgMem) {
            mem[a] = mp(ret, nxt);
        } else {
            return mp(ret, nxt);
        }
    }
    return mem[a];
}

int main() {
    int i;
    int k, y, z;
    
//for(N=1;N<=255;++N){
    for (; ~scanf("%d", &N); ) {
        mem.clear();
        vint a(1, 1);
        int res = calc(a).first;
//cout<<"res = "<<res<<endl;
        printf("%d\n", res - 1);
        for (; a.back() != N; ) {
            int m = a.size();
            vint aa = a;
            aa.push_back(0);
            int nxt = calc(a).second;
            for (k = 8; k >= 1; k /= 2) {
                for (y = 0; y <= m; ++y) for (z = 0; z <= m; ++z) {
                    int b = aa[y] + k * aa[z];
                    if (b == nxt) {
                        printf("lea e%cx, [e%cx + %d*e%cx]\n", 'a' + m, 'a' + y, k, 'a' + z);
                        aa[m] = b;
                        a = aa;
                        goto found;
                    }
                }
            }
assert(0);
        found:;
        }
    }
    
    return 0;
}