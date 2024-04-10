#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e5 + 2;
const int MAX_LOG = 18;
const int BIG = 1e9 + 239;

int main()
{
    /*#define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);*/
    cin.sync_with_stdio(0);
    int n, mn, mx;
    mx = 2010;
    mn = 2100;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mn = min(mn, a);
        mx = max(mx, a);
    }
    cout << (mn + mx) / 2;
    return 0;
}