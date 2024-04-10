#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

bool check(int a, int b, int c, int d) {
    return (((a < c) && (c < b) && (b < d)) || ((c < a) && (a < d) && (d < b)));
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<tuple<int, int>> pairs;
        vector<bool> seen(2 * n, false);
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            seen[x] = true, seen[y] = true;
            pairs.emplace_back(x, y);
        }

        vector<int> remaining;
        for (int i = 0 ; i < 2 * n; i++) {
            if (!seen[i]) remaining.push_back(i);
        }

        sort(remaining.begin(), remaining.end());

        int count = (n - k - 1) * (n - k) / 2;
        for (int i = 0; i < n - k; i++) {
            int a = remaining[i], b = remaining[i + n - k];
            for (auto [c, d] : pairs) {
                if (c > d) swap(c, d);
                if (check(a, b, c, d)) count++;
            }
        }

        for (int i = 0; i < k; i++) {
            for (int j = i; j < k; j++) {
                auto [a, b] = pairs[i];
                auto [c, d] = pairs[j];
                if (a > b) swap(a, b);
                if (c > d) swap(c, d);
                if (check(a, b, c, d)) count++;
            }
        }

        cout << count << "\n";

    }
}