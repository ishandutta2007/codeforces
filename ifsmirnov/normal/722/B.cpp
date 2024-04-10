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
// #define sz(x) int((x).size())

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    set<char> v = {'a','y','u','i','o','e'};
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    string s;
    getline(cin, s);
    forn(i, n) {
        getline(cin, s);
        int cnt = 0;
        for (char c: s) cnt += v.count(c);
        if (cnt != a[i]) {
            cout << "NO" << endl;
            return 0;;
        }
    }
    cout << "YES" << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}