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
        ll W;
        cin >> n >> W;
        vector<tuple<ll, int>> a(n);
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            a[i] = { x, i + 1 };
        }
        sort(a.begin(), a.end(), greater<tuple<ll, int>>());
        ll curr_sum = 0;
        vector<int> sol;
        for (int i = 0; i < n; i++) {
            if (curr_sum + get<0>(a[i]) <= W) {
                sol.push_back(get<1>(a[i]));
                curr_sum += get<0>(a[i]);
            }
        }
        
        if (curr_sum < (W + 1) / 2) {
            cout << "-1\n";
        } else {
            cout << sol.size() << "\n";
            for (auto el : sol) cout << el << " ";
            cout << "\n";
        }
    }
}