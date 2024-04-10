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

const double PI = acos(-1);

double mod(double x) { return fmod(fmod(x, 1.0) + 1.0, 1.0); }

int N;
double L, V1, V2;
double A[100010];

int psLen;
pair<double,int> ps[200010];
double ans[100010];

int main() {
    int i;
    
    for (; ~scanf("%d", &N); ) {
        L = in();
        V1 = in();
        V2 = in();
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        for (i = 0; i < N; ++i) {
            A[i] /= L * 2;
            A[i] = mod(A[i] + PI);
        }
        double S = 0.5 * V2 / (V1 + V2);
        psLen = 0;
        for (i = 0; i < N; ++i) {
            ps[psLen++] = mp(mod(A[i]), -1);
            ps[psLen++] = mp(mod(A[i] - S), +1);
        }
        sort(ps, ps + psLen);
        ps[psLen].first = ps[0].first + 1;
        memset(ans, 0, sizeof(ans));
        int now = 0;
        for (i = 0; i < N; ++i) {
            if (0 <= A[i] && A[i] < S) {
                ++now;
            }
        }
        for (i = 0; i < psLen; ++i) {
            now += ps[i].second;
            ans[now] += ps[i + 1].first - ps[i].first;
        }
        for (i = 0; i <= N; ++i) {
            printf("%.10f\n", ans[i]);
        }
    }
    
    return 0;
}