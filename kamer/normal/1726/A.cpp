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
#include <complex>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        int min_left = 1000, min_right = 1000, max_left = -1, max_right = -1;
        for (int i = 1; i < n; i++) {
            min_right = min(min_right, a[i]);
            max_right = max(max_right, a[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            min_left = min(min_left, a[i]);
            max_left = max(max_left, a[i]);
        }

        int max_pair = a[n - 1] - a[0];
        for (int i = 1; i < n; i++) {
            max_pair = max(max_pair, a[i - 1] - a[i]);
        }
        max_pair = max(max_pair, max_right - a[0]);
        max_pair = max(max_pair, a[n - 1] - min_left);
        cout << max_pair << "\n";
    }
}