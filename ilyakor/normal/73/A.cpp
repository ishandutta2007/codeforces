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
    int64 x, y, z, k;
    cin >> x >> y >> z >> k;
    if (x > y) swap(x, y);
    if (x > z) swap(x, z);
    if (y > z) swap(y, z);
    int64 res = 1;

    int64 k1 = k / 3;
    k1 = min(k1, x - 1);
    res *= k1 + 1;
    k -= k1;

    int64 k2 = k / 2;
    k2 = min(k2, y - 1);
    res *= k2 + 1;
    k -= k2;

    int64 k3 = k;
    k3 = min(k3, z - 1);
    res *= k3 + 1;
    k -= k3;

    cout << res << "\n";
    return 0;
}