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

int n;

int go(int x, int y)
{
    if (x == 0) return y;
    if (y == n) return n + x;
    if (x == n) return 3 * n - y;
    return 4 * n - x;
}

int main()
{
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int l1 = go(x1, y1);
    int l2 = go(x2, y2);
    int res = abs(l1 - l2);
    res = min(res, 4 * n - res);
    cout << res << "\n";
    return 0;
}