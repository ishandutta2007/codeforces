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
    int n = s.size();

    for (int i = 0; i < n; i++) {
        string now1;
        for (int j = i; j < n; j++) {
            string now2 = now1;
            for (int k = j; k >= 0; k--) {
                now2.push_back(s[k]);
                if (now2 == t) {
                    cout << "YES\n";
                    return;
                }
            }
            now1.push_back(s[j]);
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