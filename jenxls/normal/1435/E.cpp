#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

#define int ll

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int T;
int a, b, c, d;

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> a >> b >> c >> d;

        if (a > b * c) {
            cout << "-1\n";
            continue;
        }

        int tt = a / (d * b);

        int res = (tt + 1) * a;
        res -= tt * (tt + 1) / 2 * d * b;

        cout << res << '\n';
    }
}