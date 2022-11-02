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
    int n, m;
    int64 x, y;
    cin >> n >> m >> x >> y;
    vector<pair<int64, int> > a(n), b(m);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i].first = x;
        a[i].second = i;
    }
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        b[i].first = x;
        b[i].second = i;
    }

    sort(all(a));
    sort(all(b));
    int res = 0;

    int ai = 0;
    vector<ii> vr;
    for (int bi = 0; bi < sz(b); ++bi) {
        while (ai < sz(a) && a[ai].first + y < b[bi].first) ++ai;
        if (ai < sz(a) && a[ai].first - x <= b[bi].first) {
            ++res;
            vr.pb(ii(a[ai].second, b[bi].second));
            ++ai;
        }
    }

    cout << res << "\n";
    for (int i = 0; i < sz(vr); ++i)
        printf("%d %d\n", vr[i].first + 1, vr[i].second + 1);
    return 0;
}