#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;

const int maxn = 100500;

char s[maxn];
int d[maxn];
int b[maxn];
int n;

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    scanf("%d", &n);
    scanf("%s", s);
    forn(i, n) scanf("%d", &d[i]);

    int pos = 0;
    while (true) {
        b[pos] = 1;
        if (s[pos] == '>') pos += d[pos];
        else pos -= d[pos];
        if (pos < 0 || pos >= n) {
            cout << "FINITE" << endl;
            return 0;
        }
        if (b[pos]) {
            cout << "INFINITE" << endl;
            return 0;
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}