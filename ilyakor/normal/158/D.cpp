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
    int n;
    cin >> n;
    vi v(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        res += v[i];
    }

    for (int m = 3; m <= n; ++m) if (n % m == 0) {
        int delta = n / m;
        vi val(delta, 0);
        for (int i = 0; i < n; ++i)
            val[i % delta] += v[i];

        for (int i = 0; i < sz(val); ++i)
            res = max(res, val[i]);
    }

    cout << res << "\n";
    return 0;
}