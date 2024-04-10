#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 1000;

char c[maxn][maxn];


int x, y;
int cur = 0;

void makec(int c) {
    while (cur != c + 1) {
        ::c[x][y] = 'X';
        y += 2;
        if (y + 10 > maxn) x += 3, y = 0;
        --cur;
        if (cur < 0) cur = 255;
    }

    x += 2;
    y = 0;
    ::c[x][0] = ::c[x+1][0] = 'X';
    x += 3;
    --cur;
}

int main() {
#ifdef LOCAL
    freopen("g.in", "r", stdin);
#endif
    memset(c, '.', sizeof c);
    forn(i, maxn) c[i][maxn-1] = 0;

    string s;
    cin >> s;
    for (char c: s) {
        makec(c);
    }

    // cerr << avail[4] << endl;
    forn(i, x+1) cout << c[i] << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}