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

const double EPS = 1e-15;
const double PI = acos(-1.0);

int N;
double R, S;

bool solve() {
    if (R < S) return (N <= 0);
    if (R < S * 2) return (N <= 1);
    double th = asin(S / (R - S));
    return (th * N <= PI + EPS);
}

int main() {
    
    
    for (; ~scanf("%d%lf%lf", &N, &R, &S); ) {
        bool res = solve();
        puts(res ? "YES" : "NO");
    }
    
    return 0;
}