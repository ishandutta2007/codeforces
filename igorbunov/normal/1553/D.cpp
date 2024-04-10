#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    string s, t;
    cin >> s >> t;
    int ind1 = t.size() - 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == t[ind1]) {
            ind1--;
            if (ind1 == -1) {
                cout << "YES\n";
                return;
            }
            continue;
        } else {
            i--;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}