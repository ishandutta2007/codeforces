//  Codeforces Beta Round #68

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

int N, Q;
map<int,int> R;
set<int> S;
set< pint,greater<pint> > P;

int typ[100010], A[100010], B[100010];
int aslen, as[200010];

int bitn;
int bit[200010];
void bit_add(int x, int val) { for (; x <= bitn; x += x & -x) bit[x] += val; }
int bit_cal(int x) { int ret = 0; for (; x > 0; x &= x - 1) ret += bit[x]; return ret; }

int main() {
    int i;
    int x, a, b;
    
    for (; ~scanf("%d%d", &N, &Q); ) {
        S.clear();
        P.clear();
        S.insert(0);
        S.insert(N + 1);
        P.insert(mp(N, N));
        for (i = 0; i < Q; ++i) {
            x = in();
            if (x) {
                if (R.count(x)) {
                    typ[i] = -1; A[i] = B[i] = R[x];
                    set<int>::iterator it = S.find(R[x]), ita, itb;
                    ita = it; --ita;
                    itb = it; ++itb;
                    P.erase(mp(*it - *ita - 1, *it - 1));
                    P.erase(mp(*itb - *it - 1, *itb - 1));
                    P.insert(mp(*itb - *ita - 1, *itb - 1));
                    S.erase(R[x]);
                    R.erase(x);
                } else {
                    set<pint>::iterator pit = P.begin();
//cout<<pit->first<<" "<<pit->second<<endl;
                    R[x] = pit->second - (pit->first - 1) / 2;
                    S.insert(R[x]);
//cout<<"R[x] = "<<R[x]<<endl;
                    set<int>::iterator it = S.find(R[x]), ita, itb;
                    ita = it; --ita;
                    itb = it; ++itb;
                    P.erase(mp(*itb - *ita - 1, *itb - 1));
                    P.insert(mp(*it - *ita - 1, *it - 1));
                    P.insert(mp(*itb - *it - 1, *itb - 1));
                    typ[i] = +1; A[i] = B[i] = R[x];
                }
            } else {
                a = in();
                b = in();
                if (a > b) swap(a, b);
                typ[i] = 0; A[i] = a; B[i] = b;
            }
//cout<<"Q "<<typ[i]<<" "<<A[i]<<" "<<B[i]<<endl;
        }
        aslen = 0;
        for (i = 0; i < Q; ++i) {
            as[aslen++] = A[i];
            as[aslen++] = B[i];
        }
        sort(as, as + aslen);
        aslen = unique(as, as + aslen) - as;
        for (i = 0; i < Q; ++i) {
            A[i] = lower_bound(as, as + aslen, A[i]) - as + 1;
            B[i] = lower_bound(as, as + aslen, B[i]) - as + 1;
        }
        bitn = aslen + 5;
        memset(bit, 0, sizeof(bit));
        for (i = 0; i < Q; ++i) {
            if (typ[i]) {
                bit_add(A[i], typ[i]);
            } else {
                int res = bit_cal(B[i]) - bit_cal(A[i] - 1);
                printf("%d\n", res);
            }
        }
    }
    
    return 0;
}