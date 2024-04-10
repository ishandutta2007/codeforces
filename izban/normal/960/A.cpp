#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    string s;
    while (cin >> s) {
        int n = s.length();

        vector<pair<char, int>> a;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;

            a.push_back({s[i], j - i});
            i = j - 1;
        }

        bool ok = a.size() == 3 && a[0].first == 'a' && a[1].first == 'b' && a[2].first == 'c' && (a[2].second == a[0].second || a[2].second == a[1].second);
        cout << (ok ? "YES" : "NO") << endl;
    }


#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}