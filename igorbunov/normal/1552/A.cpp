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
    vector<int> cnt(26);
    string s;
    cin >> s >> s;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    int ans = s.size();
    int l = 0;
    for (int _ = 0; _ < 26; _++) {
        int r = l + cnt[_];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - 'a' == _) {
                if (i >= l && i < r) {
                    ans--;
                }
            }
        }
        l += cnt[_];
    }
    cout << ans << endl;
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