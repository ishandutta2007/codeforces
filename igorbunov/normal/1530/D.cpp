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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    set<int> all;
    for (int i = 0; i < n; i++) {
        all.insert(i);
    }
    int bruh = 0;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (all.find(a[i]) != all.end()) {
            ans[i] = a[i];
            bruh++;
            all.erase(a[i]);
        }
    }

    if (bruh == n - 1) {
        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) {
                continue;
            }
            if (*all.begin() != i) {
                break;
            }
            ans[i] = i;
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                if (ans[j] == a[i]) {
                    swap(ans[j], ans[i]);
                    break;
                }
            }
        }
    }
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) {
            continue;
        }
        if (all.size() >= 2) {
            int kek1 = *all.begin();
            int kek2 = *all.rbegin();
            if (i != kek1) {
                all.erase(all.begin());
                ans[i] = kek1;
            } else {
                auto it = all.end();
                it--;
                all.erase(it);
                ans[i] = kek2;
            }
        } else {
            ans[i] = *all.begin(); 
            if (ans[i] == i) {
                swap(ans[i], ans[last]);
            }
        }
        last = i;
    }
    cout << bruh << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
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