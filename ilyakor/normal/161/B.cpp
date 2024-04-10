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
    int n, k;
    cin >> n >> k;
    vector<ii> v1, v2;
    int64 res = 0;
    for (int i = 0; i < n; ++i) {
        int c, t;
        cin >> c >> t;
        if (t == 1)
            v1.pb(ii(c, i));
        else
            v2.pb(ii(c, i));

        res += c;
    }

    res *= 2LL;

    vector<vi> vr(k);

    sort(all(v1));
    sort(all(v2));

    if (k > sz(v1)) {
        for (int i = 0; i < sz(v1); ++i) {
            res -= v1[i].first;
            vr[i].pb(v1[i].second);
        }

        for (int i = 0; i < sz(v2); ++i) {
            int ind = min(k - 1, sz(v1) + i);
            vr[ind].pb(v2[i].second);
        }
    } else {
        reverse(all(v1));
        for (int i = 0; i < k - 1; ++i) {
            res -= v1[i].first;
            vr[i].pb(v1[i].second);
        }

        for (int i = k - 1; i < sz(v1); ++i)
            vr[k - 1].pb(v1[i].second);

        for (int i = 0; i < sz(v2); ++i)
            vr[k - 1].pb(v2[i].second);

        if (sz(v1) || sz(v2)) {
            int64 tmp = (int64)(1E18);
            if (sz(v1)) tmp = min(tmp, (int64) v1[sz(v1) - 1].first);
            if (sz(v2)) tmp = min(tmp, (int64) v2[0].first);

            res -= tmp;
        }
    }

    cout << (res / 2LL) << "." << (5LL * (res % 2LL)) << "\n";
    for (int i = 0; i < k; ++i) {
        sort(all(vr[i]));
        cout << sz(vr[i]) << " ";
        for (int j = 0; j < sz(vr[i]); ++j)
            cout << (vr[i][j] + 1) << " ";
        cout << "\n";
    }
    return 0;
}