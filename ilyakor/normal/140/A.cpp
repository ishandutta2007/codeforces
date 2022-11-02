/*
 * Powered by C++Helper v0.001alpha
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const double eps = 1E-8;

int main() {
    int n;
    double R, r;
    cin >> n >> R >> r;
    int m = 0;
    while (1) {
        double d = R - r;
        if (d < -eps) break;
        if (d < r - eps) {
            ++m;
            break;
        }

        double l = r / d;
        l = max(l, 0.0);
        l = min(l, 1.0);
        double alpha = asin(l);
        double t = 2. * asin(1.) / alpha;

        m += (int) (t + eps);
        break;
    }

    printf("%s\n", m >= n ? "YES" : "NO");
    return 0;
}