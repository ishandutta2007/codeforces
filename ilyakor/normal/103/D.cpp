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

const int maxn = 310 * 1000;

vector<ii> q[maxn];

int64 s[maxn];

int main()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        q[y].pb(ii(x, i));
    }
    vector<int64> res(m, 0);
    int buben = max(1, (int) sqrt(n + 1.));
    for (int i = 1; i <= buben; ++i) {
        if (!sz(q[i])) continue;
        memset(s, 0, sizeof(s));
        for (int j = 0; j < n; ++j) {
            s[j] = v[j];
            if (j - i >= 0)
                s[j] += s[j - i];
        }
        for (int j = 0; j < sz(q[i]); ++j) {
            int st = q[i][j].first;
            int f = n - n % i + st % i + i;
            f = max(f, st);
            while (f >= n)
                f -= i;
            int64 cur = s[f];
            if (st - i >= 0) cur -= s[st - i];
            res[q[i][j].second] = cur;
        }
    }
    for (int i = buben + 1; i <= n; ++i)
        for (int j = 0; j < sz(q[i]); ++j) {
            int64 cur = 0;
            for (int t = q[i][j].first; t < n; t += i)
                cur += v[t];
            res[q[i][j].second] = cur;
        }
    for (int i = 0; i < m; ++i)
        cout << res[i] << "\n";
    return 0;
}