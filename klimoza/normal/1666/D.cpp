#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <random>
#include <chrono>
#include <fstream>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream> 
#include <utility>
#include <functional>
#include <bitset>
#include <cassert>

using namespace std;
using ll = long long;
using ld = long double;

// #define int long long

#define pii pair<int, int>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define mp make_pair

const ld eps = 1e-8;
// const ll mod = 998244353;
const ll mod = 1e9 + 7;
const int MAXN = 3e5;
const int inf0 = 1e9 + 10;
const ll inf = 2e18 + 10;

void solve();

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cout << fixed;
    cout.precision(15);
    solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;
        int j = s.size() - 1;
        vector <bool> was(26);
        bool bad = 0;
        for (int i = t.size() - 1; i >= 0; i--) {
            char need = t[i];
            while (j >= 0 && s[j] != need) {
                was[s[j] - 'A'] = 1;
                j--;
            }
            if (j < 0 || was[need - 'A']) {
                bad = 1;
                break;
            }
            j--;
        }
        if (bad)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}