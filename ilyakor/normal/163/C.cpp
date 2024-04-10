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

int64 T;

int64 norm(int64 x) {
    while (x < 0) x += T;
    while (x >= T) x -= T;
    return x;
}

int main()
{
    int n;
    int64 l, v1, v2;
    cin >> n >> l >> v1 >> v2;
    vi a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    T = 2LL * l;
    T *= (v1 + v2);

    vector<pair<int64, int> > ev;
    for (int i = 0; i < n; ++i) {
        int64 t = a[i];
        t *= (v1 + v2);
        ev.pb(mp(norm(t), -1));

        t -= l * v2;
        ev.pb(mp(norm(t), 1));
    }
    ev.pb(mp(0, 0));
    ev.pb(mp(T, 0));
    sort(all(ev));

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0 && (int64)a[i] * (int64)(v1 + v2) < v2 * l) ++cur;
    }

    vector<int64> d(n + 1, 0);
    for (int i = 0; i < sz(ev); ++i) {      
        if (i > 0 && ev[i].first != ev[i - 1].first)
            d[cur] += ev[i].first - ev[i - 1].first;
        cur += ev[i].second;
    }

    for (int i = 0; i <= n; ++i) {
        double x = d[i];
        x /= T;
        printf("%.15lf\n", x);
    }
    return 0;
}