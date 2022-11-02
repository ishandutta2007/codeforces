#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef pair<int64, int64> II;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

int main() {
    int n;
    cin >> n;
    vector<II> v;
    for (int i = 0; i < n; ++i) {
        int64 x, y;
        cin >> x >> y;
        v.pb(II(y, x));
    }
    
    int m;
    cin >> m;
    vector<int64> p(m);
    for (int i = 0; i < m; ++i)
        cin >> p[i];

    int64 cur = 0, s = 0;
    sort(all(v));
    int64 res = 0;
    for (int i = 0; i < sz(v); ++i) {       
        int64 x = v[i].second;
        while (x > 0) {
            while (cur < m && p[(int)cur] <= s) ++cur;

            int64 t = x;
            if (cur < m) t = min(t, p[(int)cur] - s);
            res += v[i].first * (cur + 1LL) * t;
            x -= t;
            s += t;
        }
    }

    cout << res << "\n";
    return 0;
}