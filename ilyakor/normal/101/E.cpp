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

int64 d[2][30000];

const int BUBEN = 11000;

bitset<21000> from[BUBEN];

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vi a(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vi b(m, 0);
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < BUBEN; ++i)
        from[i].reset();
    for (int i = n; i > 0; --i) {
        int cur = i % 2;
        int pr = (i + 1) % 2;
        memset(d[cur], 0, sizeof(d[cur]));
        for (int j = m; j > 0; --j) {
            int64 val1 = d[pr][j], val2 = d[cur][j + 1];
            if (i == n) val1 = -10000;
            if (j == m) val2 = -10000;
            if (val1 >= val2) {
                d[cur][j] = val1;
                if (i < BUBEN)
                    from[i][j] = true;
            } else {
                d[cur][j] = val2;
                if (i < BUBEN)
                    from[i][j] = false;
            }
            if (d[cur][j] < 0) d[cur][j] = 0;
            int val = (a[n - i] + b[m - j]) % p;
            d[cur][j] += val;
        }
    }
    int64 res = d[1][1];
    cout << res << "\n";
    int x = 1, y = 1;
    string s;
    while (x < BUBEN && (x != n || y != m)) {
        if (from[x][y]) {
            s += 'C';
            ++x;
        } else {
            s += 'S';
            ++y;
        }
    }
    memset(d, 0, sizeof(d));
    for (int i = n; i > 0; --i) {
        int cur = i % 2;
        int pr = (i + 1) % 2;
        memset(d[cur], 0, sizeof(d[cur]));
        for (int j = m; j > 0; --j) {
            int64 val1 = d[pr][j], val2 = d[cur][j + 1];
            if (i == n) val1 = -10000;
            if (j == m) val2 = -10000;
            if (val1 >= val2) {
                d[cur][j] = val1;
                if (i >= BUBEN)
                    from[i - BUBEN][j] = true;
            } else {
                d[cur][j] = val2;
                if (i >= BUBEN)
                    from[i - BUBEN][j] = false;
            }
            if (d[cur][j] < 0) d[cur][j] = 0;
            int val = (a[n - i] + b[m - j]) % p;
            d[cur][j] += val;
        }
    }
    while (x != n || y != m) {
        if (from[x - BUBEN][y]) {
            s += 'C';
            ++x;
        } else {
            s += 'S';
            ++y;
        }
    }
    reverse(all(s));
    cout << s << "\n";
    return 0;
}