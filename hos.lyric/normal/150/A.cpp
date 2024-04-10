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

Int N;
int psLen;
Int ps[1010];

int main() {
    Int n, d;
    
    for (; cin >> N; ) {
        n = N;
        psLen = 0;
        for (d = 2; d * d <= n; ++d) {
            for (; n % d == 0; n /= d) {
                ps[psLen++] = d;
            }
        }
        if (n > 1) {
            ps[psLen++] = n;
        }
        if (psLen <= 1) {
            puts("1");
            puts("0");
        } else if (psLen == 2) {
            puts("2");
        } else {
            puts("1");
            cout << (ps[0] * ps[1]) << endl;
        }
    }
    
    return 0;
}