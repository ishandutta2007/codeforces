#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
// #define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
// #define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
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
#define sz(x) int((x).size())

int main() {
#ifdef LOCAL
//     freopen("c.in", "r", stdin);
#endif

    string s;
    cin >> s;
    int res = 1;
    for (char c: s) {
        int x;
        if (c >= '0' && c <= '9') x = c-'0';
        else if ('A' <= c && c <= 'Z') x = c-'A' + 10;
        else if ('a' <= c && c <= 'z') x = c-'a' + 36;
        else if (c == '-') x = 62;
        else if (c == '_') x = 63;
        else assert(false);
        int cnt = 6;
        while (x) {
            --cnt;
            x = x&(x-1);
        }
        forn(i, cnt)
            res = (i64)res*3%1000000007;
    }
    cout << res << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}