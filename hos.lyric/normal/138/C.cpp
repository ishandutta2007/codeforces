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

#define MAXN 100010
#define MAXM 100010
#define MAX 500010

int N, M;
int A[MAXN], H[MAXN];
int L[MAXN], R[MAXN];
int B[MAXM];
double Z[MAXM];

int psLen;
pair<pint,pint> ps[MAX];

int cs[110];
double logs[110];

int main() {
    int i, j, k;
    int p;
    
    for (p = 0; p < 100; ++p) {
        logs[p] = log(1.0 - p / 100.0);
    }
    
    for (; ~scanf("%d%d", &N, &M); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
            H[i] = in();
            L[i] = in();
            R[i] = in();
        }
        for (j = 0; j < M; ++j) {
            B[j] = in();
            Z[j] = in();
        }
        psLen = 0;
        for (i = 0; i < N; ++i) {
            ps[psLen++] = mp(mp(A[i] - H[i], -1), mp(L[i], +1));
            ps[psLen++] = mp(mp(A[i]       , -1), mp(L[i], -1));
            ps[psLen++] = mp(mp(A[i]       , +1), mp(R[i], +1));
            ps[psLen++] = mp(mp(A[i] + H[i], +1), mp(R[i], -1));
        }
        for (j = 0; j < M; ++j) {
            ps[psLen++] = mp(mp(B[j], 0), mp(j, 0));
        }
        sort(ps, ps + psLen);
        double ans = 0.0;
        //double prob = 1.0;
        //int zero = 0;
        memset(cs, 0, sizeof(cs));
        for (k = 0; k < psLen; ++k) {
            switch (ps[k].second.second) {
                case -1: {
                    p = ps[k].second.first;
                    /*
                    if (p < 100) {
                        prob /= (1.0 - p / 100.0);
                    } else {
                        --zero;
                    }
                    */
                    --cs[p];
                } break;
                case +1: {
                    p = ps[k].second.first;
                    /*
                    if (p < 100) {
                        prob *= (1.0 - p / 100.0);
                    } else {
                        ++zero;
                    }
                    */
                    ++cs[p];
                } break;
                case  0: {
                    j = ps[k].second.first;
                    //ans += Z[j] * (zero ? 0.0 : prob);
                    if (!cs[100]) {
                        double sum = 0.0;
                        for (p = 0; p < 100; ++p) {
                            sum += cs[p] * logs[p];
                        }
                        ans += Z[j] * exp(sum);
                    }
                } break;
                default: {
                    assert(0);
                }
            }
        }
        printf("%.10f\n", ans);
    }
    
    return 0;
}