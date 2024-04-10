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

int main()
{
    int64 n, m, a, b;
    cin >> n >> m >> a >> b;
    --a;
    --b;
    int64 x = a % m;
    int64 y = b % m;
    int64 cnt = b / m - a / m;
    int64 res = 0;
    if (cnt == 0) {
        res = 1;
    } else if (cnt == 1) {
        res = 2;
        if (x == 0 && (y == m - 1 || b == n - 1)) --res;
    } else {
        res = 3;
        if (x == 0) --res;
        if (y == m - 1 || b == n - 1) --res;
        if ((y + 1) % m == x) res = min(res, 2LL);
    }
    cout << res << "\n";
    return 0;
}