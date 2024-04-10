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
    string s;
    cin >> s;
    int ans = 10;
    {
        vector<int> now(10);
        for (int i = 0; i < 10; i++) {
            if (s[i] == '1') {
                now[i] = 1;
            }
            if (s[i] == '0') {
                now[i] = 0;
            }
            if (s[i] == '?') {
                now[i] = i % 2;
            }
        }

        int now1 = 0;
        int now2 = 0;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                now1 += now[i];
            } else {
                now2 += now[i];
            }

            if (now1 > now2) {
                int ost2 = 5 - (i + 1) / 2;
                if (now1 > now2 + ost2) {
                    ans = min(ans, i + 1);
                }
            } else {
                int ost1 = 4 - i / 2;
                if (now2 > now1 + ost1) {
                    ans = min(ans, i + 1);
                }
            }
        }
    }
    {
        vector<int> now(10);
        for (int i = 0; i < 10; i++) {
            if (s[i] == '1') {
                now[i] = 1;
            }
            if (s[i] == '0') {
                now[i] = 0;
            }
            if (s[i] == '?') {
                now[i] = (i + 1) % 2;
            }
        }

        int now1 = 0;
        int now2 = 0;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                now1 += now[i];
            } else {
                now2 += now[i];
            }

            if (now1 > now2) {
                int ost2 = 5 - (i + 1) / 2;
                if (now1 > now2 + ost2) {
                    ans = min(ans, i + 1);
                }
            } else {
                int ost1 = 4 - i / 2;
                if (now2 > now1 + ost1) {
                    ans = min(ans, i + 1);
                }
            }
        }
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