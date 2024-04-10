#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <bitset>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

template<class T> T abs(T x) { return x > 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

const int64 inf = (int64)(1E15);

int64 calc(int64 a1, int64 a2, int64 a3) {
    int64 d23 = a2 + a3;
    if (d23 % 2LL == 1LL) return inf;
    d23 /= 2LL;
    int64 delta = abs(a2 - d23);
    return delta + d23;
}

int main() {
    int64 a[3];
    for (int i = 0; i < 3; ++i)
        cin >> a[i];
    int64 res = inf;
    for (int it = 0; it < 3; ++it) {
        res = min(res, calc(a[0], a[1], a[2]));
        swap(a[0], a[(it + 1) % 3]);
    }
    if (res == inf) res = -1;
    cout << res << "\n";
    return 0;
}