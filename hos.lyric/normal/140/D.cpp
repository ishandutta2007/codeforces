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

const int T = 350 + 360;
const int S = 350;

int N, M;
int A[110], B[110];

int main() {
    int i;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        sort(A, A + N);
        for (i = 0; i < N; ++i) {
            B[i + 1] = B[i] + A[i];
        }
        M = 0;
        for (i = 0; i <= N; ++i) {
            if (B[i] <= T) {
                M = i;
            }
        }
        int pen = 0;
        for (i = 1; i <= M; ++i) {
            pen += max(B[i] - S, 0);
        }
        printf("%d %d\n", M, pen);
    }
    
    return 0;
}