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

void fail() {
    cout << -1 << endl;
    exit(0);
}

int u[1010];
vector<int> fr;

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    int n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    u[a] = u[b] = u[c] = u[d] = 1;
    fore(i, 1, n) if (!u[i]) fr.push_back(i);
    if (n == 4) fail();
    if (k < n+1) fail();

    cout << a << " " << c << " ";
    for (int x: fr) cout << x << " ";
    cout << d << " " << b << endl;

    cout << c << " " << a << " ";
    for (int x: fr) cout << x << " ";
    cout << b << " " << d << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}