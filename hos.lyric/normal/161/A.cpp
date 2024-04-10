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

int M, N;
int X, Y;
pint A[100010], B[100010];

int ansLen;
pint ans[100010];

int main() {
    int i, j;
    
    for (; ~scanf("%d%d", &M, &N); ) {
        X = in();
        Y = in();
        for (i = 0; i < M; ++i) {
            A[i] = mp(in(), i);
        }
        for (j = 0; j < N; ++j) {
            B[j] = mp(in(), j);
        }
        sort(A, A + M);
        sort(B, B + N);
        set<pint> bs;
        for (j = 0; j < N; ++j) {
            bs.insert(B[j]);
        }
        ansLen = 0;
        for (i = 0; i < M; ++i) {
            int x = A[i].first - X;
            int y = A[i].first + Y;
            set<pint>::iterator it = bs.lower_bound(mp(x, -1));
            if (it != bs.end()) {
                if (x <= it->first && it->first <= y) {
                    ans[ansLen++] = mp(A[i].second, it->second);
                    bs.erase(it);
                }
            }
        }
        printf("%d\n", ansLen);
        for (i = 0; i < ansLen; ++i) {
            printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        }
    }
    
    return 0;
}