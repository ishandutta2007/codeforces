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
const ll MOD = 998244353;


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
        ll counter = n;
        vector<tuple<int, int, int>> force;
        force.emplace_back(n - 1, a[n - 1], 1);
        for (int i = n - 2; i >= 0; i--) {
            vector<tuple<int, int, int>> t_force;
            t_force.emplace_back(i, a[i], 1);
            int curr_counter = 0;
            int curr_d = 1;

            for (auto [index, value, d] : force) {
                int opt_d = (a[i] - 1) / value + 1;
                if (opt_d > curr_d) {
                    t_force.emplace_back(index, a[i] / opt_d, opt_d);
                    curr_d = opt_d;
                    curr_counter++;
                }
            }

            int k = t_force.size();
            for (int j = 0; j < k - 1; j++) {
                auto [index, val, d] = t_force[j];
                auto [n_index, n_val, n_d] = t_force[j + 1];
                counter = (counter + ((ll) (i + 1)) * ((ll) (n_index - index)) * ((ll) d)) % MOD;
            }
            auto [index, val, d] = t_force[k - 1];
            counter = (counter + ((ll) (i + 1)) * ((ll) (n - index)) * ((ll) d)) % MOD;
            force = t_force;
        }

        for (int i = 0; i < n; i++) {
            counter = (counter - ((ll) (i + 1)) * ((ll) (n - i))) % MOD;
            if (counter < 0) counter += MOD;
        }
        
        /*
        for (int i = 0; i < n; i++) {
            cout << "T " << i << "\n";
            for (auto [index, value, d] : force[i]) {
                cout << "G " << index << " " << value << " " << d << "\n";
            }
            cout << "F " << i << "\n";
        }
        */

        cout << counter << "\n";
    }
}