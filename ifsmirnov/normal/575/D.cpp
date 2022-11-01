#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int solve()
{
    int n = 2001;
    cout << n << '\n';
    forn (i, 1000)
        cout << i + 1 << ' ' << 1 << ' ' << i + 1 << ' ' << 2 << '\n';
    cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << 2 << '\n';
    forn (i, 1000)
        cout << i + 1 << ' ' << 1 << ' ' << i + 1 << ' ' << 2 << '\n';
    return 0;
}