#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<bool> isPerm(n, false);
    vector<vector<int>> pos(n, vector<int>());
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }

    int currNum = 0;
    int left = 0;
    int right = n;
    while (true) {
        if (currNum == n - 1) {
            for (int i = 0; i < n; i++) {
                isPerm[i] = true;
            }
            break;
        }

        if (pos[currNum].size() == 0) {
            for (int i = n - currNum; i < n; i++) isPerm[i] = true;
            break;
        }

        if (pos[currNum].size() >= 2) {
            for (int i = n - 1 - currNum; i < n; i++) isPerm[i] = true;
            break;
        }

        if ((pos[currNum][0] != left) && (pos[currNum][0] != (right - 1))) {
            for (int i = n - 1 - currNum; i < n; i++) isPerm[i] = true;
            break;
        }

        if (pos[currNum][0] == left) {
            left++;
        } else {
            right--;
        }

        currNum++;
    }

    // Analyze 0 case
    isPerm[0] = true;
    for (int i = 0; i < n; i++) {
        if (pos[i].size() != 1) {
            isPerm[0] = false;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (isPerm[i]) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}