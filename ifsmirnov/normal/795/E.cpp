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

int m;

int mul(i64 x, i64 y) { return x*y%m; }
int add(int x, int y) { return (x+y)%m; }

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    string s;
    cin >> s >> m;
    n = s.size();
    s += s+s;
    int res = m;
    int p = 1;
    int cur = 0;
    forn(i, n) {
        cur = add(mul(cur, 10), s[i]-'0');
        p = mul(p, 10);
    }
//     cerr << p << endl;
    forn(i, n) {
//         cerr << cur << endl;
        if (s[i] != '0') {
            res = min(res, cur);
        }
        cur = mul(cur, 10);
        cur = add(cur, m-mul(s[i]-'0', p));
        cur = add(cur, s[i]-'0');

    }
    cout << res << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}