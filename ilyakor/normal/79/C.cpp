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

const int maxn = 218 * 1000;
const int inf = 1000 * 1000 * 1000;

char s[maxn];

int main()
{
    scanf("%s", s);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int l = strlen(s);
    vi d(l, inf);
    vi nz;
    nz.pb(-1);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < n; ++j) {
            bool ok = true;
            for (int k = 0; k < sz(v[j]); ++k)
                if (i + k >= l || s[i + k] != v[j][k]) {
                    ok = false;
                    break;
                }
            if (ok) d[i] = min(d[i], i + sz(v[j]));
        }
        if (d[i] != inf)
            nz.pb(i);
    }
    ii res(0, 0);
    for (int i = 0; i < sz(nz); ++i) {
        int start = nz[i] + 1;
        int end = l;
        for (int j = 1; j < 11; ++j)
            if (i + j < sz(nz))
                end = min(end, d[nz[i + j]] - 1);
        res = max(res, ii(end - start, -start));
    }
    cout << res.first << " " << -res.second << "\n";
    return 0;
}