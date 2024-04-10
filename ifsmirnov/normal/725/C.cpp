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

string s;

int last[200];

char c[2][20];

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    cin >> s;
    memset(last, -1, sizeof last);
    int A=-1, B=-1;
    forn(i, 27) {
        if (!isupper(s[i])) continue;
        if (last[s[i]] == -1) last[s[i]] = i;
        else {
            A=last[s[i]];
            B=i;
            break;
        }
    }

    if (A+1 == B) {
        cout << "Impossible" << endl;
        return 0;
    }

    assert(A != -1);
    int d = B-A-1;

    int x = 0;
    int y = 12-d/2;

    s.erase(s.begin() + B);
    forn(i, 26) {
        c[x][y] = s[(i+A)%26];
        if (x == 0) {
            ++y;
            if (y == 13) y = 12, x = 1;
        } else {
            --y;
            if (y == -1) y = 0, x = 0;
        }
    }

    cout << c[0] << endl << c[1] << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}