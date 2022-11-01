#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;

i64 solve(string s) {
    int n = s.size();
    if (n == 1) {
        if (s[0] == '9') {
            return 1980 + s[0] - '0';
        } else {
            return 1990 + s[0] - '0';
        }
    }
    i64 sm = 0;
    i64 p = 1;
    for (char c: s) {
        sm = sm * 10 + c - '0';
        p *= 10;
    }

    i64 prev = solve(s.substr(1));
    ++prev;
    return (prev - sm + p - 1) / p * p + sm;
}

int f( int x) {
    ++x;
    return (x - 17 + 99) / 100 * 100 + 17;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    forn(i, n) {
        string s;
        cin >> s;
        cout << solve(s.substr(4)) << "\n";
    }

#ifdef HOME
    cerr << "Time: " << clock() << " ms" << endl;
#endif
}