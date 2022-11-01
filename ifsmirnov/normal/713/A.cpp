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

int get(i64 x) {
    int t = 0;
    forn(i, 19) {
        t = t * 2 + (x%10)%2;
        x /= 10;
    }
    return t;
}

int get(string s) {
    reverse(all(s));
    s += "000000000000000000000000000";
    int t = 0;
    forn(i, 19) {
        t = t * 2 + s[i] - '0';
    }
    return t;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    map<int, int> cnt;
    int n;
    cin >> n;
    forn(i, n) {
        char t;
        cin >> t;
        if (t == '+') {
            i64 x;
            cin >> x;
            ++cnt[get(x)];
        } else if (t == '-') {
            i64 x;
            cin >> x;
            --cnt[get(x)];
        } else {
            string s;
            cin >> s;
            cout << cnt[get(s)] << "\n";
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}