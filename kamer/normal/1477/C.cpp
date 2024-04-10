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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<bool> vis(n, false);
    vector<int> p;
    p.push_back(0);
    vis[0] = true;

    for (int i = 0; i < n - 1; i++) {
        int curr_index = p[p.size() - 1];
        ll best_dist = -1;
        int best_index = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && ((x[curr_index] - x[j]) * (x[curr_index] - x[j]) + (y[curr_index] - y[j]) * (y[curr_index] - y[j])) > best_dist) {
                best_index = j;
                best_dist = (x[curr_index] - x[j]) * (x[curr_index] - x[j]) + (y[curr_index] - y[j]) * (y[curr_index] - y[j]);
            }
        }
        p.push_back(best_index);
        vis[best_index] = true;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " ";
    }
}