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
//     freopen("a.in", "r", stdin);
#endif

    string s;
    cin >> s >> s;
    int cnt = 0;
    forn(i, s.size()) {
        if (s[i] == '<') ++cnt;
        else break;
    }
    ford(i, s.size()) {
        if (s[i] == '>') ++cnt;
        else break;
    }
    cout << cnt << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}