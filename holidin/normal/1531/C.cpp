#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define ld double
#define mp make_pair
using namespace std;
const int inf = 1e9;
const int N = 3e5 + 13;
vector<int> e[N];

map<int, int> sq;
map<int, int> side;
map<pair<int, int>, int> cnt;


void solve() {
    int n, k,a, b;
    string s;
    cin >> n;
    for (int m = 1; m <= n; ++m) {
        for (int p = 1; p <= m; ++p)
        if (n - p * p >= 0 && (n - p * p) % 2 == 0) {
            int n1 = n - p * p;
            vector<int> v(m, p);
            int last = p;
            for (int j = p; j < m; ++j) {
                int c = min(n1 / 2, last);
                v[j] = c;
                n1 -= 2 * c;
            }
            if (n1 == 0) {
                vector<string> s(m);
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < m; ++j)
                        s[i] += '.';
                }
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < v[i]; ++j) {
                        s[i][j] = 'o';
                        s[j][i] = 'o';
                    }
                }
                cout << m << endl;
                for (int i = m - 1; i >= 0; --i)
                    cout << s[i] << "\n";
                return;
            }
        }
    }
    cout << -1;
}



signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    solve();


}