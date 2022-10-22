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

int solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    vector<int> y(m);
    vector<int> x_index(n, -1);
    vector<int> y_index(n, -1);
    for (int i = 0; i < m; i++) {
        
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        x_index[x[i]] = i;
        y_index[y[i]] = i;
    }

    vector<bool> vis(m, false);
    int result = 0;
    for (int i = 0; i < m; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        if (x[i] == y[i]) continue;
        result++;
        int current_index = i;
        bool cycle = false;
        while (x_index[y[current_index]] != -1) {
            current_index = x_index[y[current_index]];
            if (current_index < i) {
                return 1;
            }
            if (vis[current_index]) {
                result++;
                cycle = true;
                break;
            }
            vis[current_index] = true;
            result++;
        }

        if (!cycle) {
            current_index = i;
            while (y_index[x[current_index]] != -1) {
                current_index = y_index[x[current_index]];
                vis[current_index] = true;
                result++;
            }
        }
    }
    cout << result << "\n";
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        if (solve()) {
            return 2;
        }
    }
}