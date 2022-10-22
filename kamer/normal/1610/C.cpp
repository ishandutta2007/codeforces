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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i] >> a[i];
        }

        int l = 1;
        int r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int curr_b = mid - 1;
            bool possib = false;
            for (int i = 0; i < n; i++) {
                if (curr_b < 0) break;
                if (b[i] >= curr_b && a[i] >= mid - curr_b - 1) {
                    curr_b--;
                    if (curr_b < 0) possib = true;
                }
            }

            if (possib) l = mid;
            else r = mid;
        }

        cout << l << "\n";
    }
}