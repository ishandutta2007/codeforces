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

int t;
string name() {
    string s;
    s += t%10+'A';
    s += t/10+'a';
    ++t;
    return s;
}

int n, k;

string res[100];

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    cin >> n >> k;
    forn(i, k-1) res[i] = name();
    for (int i = k-1; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "YES") {
            res[i] = name();
        } else {
            res[i] = res[i-k+1];
        }
    }
    forn(i, n)cout << res[i] << " "; cout << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}