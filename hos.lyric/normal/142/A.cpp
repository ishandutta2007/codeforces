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

const Int INF = 1001001001001001001LL;

Int N;
Int sho, dai;

void check(Int a, Int b, Int c) {
    Int tmp = (a + 1) * (b + 2) * (c + 2) - a * b * c;
    chmin(sho, tmp);
    chmax(dai, tmp);
}

int main() {
    Int a, b, c;
    
    for (; cin >> N; ) {
        sho = +INF;
        dai = -INF;
        for (a = 1; a * a * a <= N; ++a) if (N % a == 0) {
            Int n = N / a;
            for (b = a; b * b <= n; ++b) if (n % b == 0) {
                c = n / b;
                check(a, b, c);
                check(b, c, a);
                check(c, a, b);
            }
        }
        cout << sho << " " << dai << endl;
    }
    
    return 0;
}