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

char S[100010];
int is[20];

int as[20], bs[20];

int xsLen, ysLen;
char xs[100010], ys[100010];

int main() {
    int i, j;
    int ii, jj;
    int z;
    
    for (; ~scanf("%s", S); ) {
        memset(is, 0, sizeof(is));
        for (i = 0; S[i]; ++i) {
            ++is[S[i] - '0'];
        }
        int opt = is[0];
        int zm = -1, im = -1;
        for (z = 0; z <= is[0] && S[z]; ++z) for (i = 1; i < 10; ++i) {
            ii = 10 - i;
            memcpy(as, is, sizeof(is));
            memcpy(bs, is, sizeof(is));
            as[0] -= z;
            bs[0] -= z;
            if (as[i] && bs[ii]) {
                --as[i];
                --bs[ii];
                int tmp = z + 1;
                for (j = 0; j < 10; ++j) {
                    jj = 9 - j;
                    tmp += min(as[j], bs[jj]);
                }
                if (opt < tmp) {
                    opt = tmp;
                    zm = z;
                    im = i;
                }
            }
        }
//cout<<opt<<" "<<zm<<" "<<im<<endl;
        if (~zm) {
            z = zm;
            i = im;
            ii = 10 - i;
            memcpy(as, is, sizeof(is));
            memcpy(bs, is, sizeof(is));
            as[0] -= z;
            bs[0] -= z;
            --as[i];
            --bs[ii];
            xsLen = ysLen = 0;
            for (j = 0; j < 10; ++j) {
                jj = 9 - j;
                int c = min(as[j], bs[jj]);
                for (; as[j ] > c; --as[j ]) xs[xsLen++] = '0' + j ;
                for (; bs[jj] > c; --bs[jj]) ys[ysLen++] = '0' + jj;
            }
            reverse(xs, xs + xsLen);
            for (j = 0; j < 10; ++j) {
                jj = 9 - j;
                for (; as[j ] > 0; --as[j ]) xs[xsLen++] = '0' + j ;
                for (; bs[jj] > 0; --bs[jj]) ys[ysLen++] = '0' + jj;
            }
            xs[xsLen++] = '0' + i ;
            ys[ysLen++] = '0' + ii;
            for (j = 0; j < z; ++j) {
                xs[xsLen++] = '0';
                ys[ysLen++] = '0';
            }
            xs[xsLen] = ys[ysLen] = 0;
        } else {
            xsLen = ysLen = 0;
            memcpy(as, is, sizeof(is));
            for (j = 10; j--; ) {
                for (; as[j] > 0; --as[j]) {
                    xs[xsLen++] = '0' + j;
                    ys[ysLen++] = '0' + j;
                }
            }
            xs[xsLen] = ys[ysLen] = 0;
        }
        puts(xs);
        puts(ys);
    }
    
    return 0;
}