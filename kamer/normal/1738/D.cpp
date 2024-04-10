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
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        int k = n;
        for (int i = 1; i <= n; i++) {
            if (b[i] < i) {
                k = i - 1;
                break;
            }
        }

        vector<vector<int>> app(n + 2, vector<int>());
        for (int i = 1; i <= n; i++) {
            app[b[i]].emplace_back(i);
        }

        vector<int> a;
        queue<int> to_proc;
        for (auto app_el : app[0]) {
            to_proc.push(app_el);
        }
        for (auto app_el : app[n + 1]) {
            to_proc.push(app_el);
        }

        while (!to_proc.empty()) {
            queue<int> next_to_proc;
            int last_el = -1;
            while (!to_proc.empty()) {
                int el = to_proc.front();
                to_proc.pop();
                if (!app[el].empty()) {
                    last_el = el;
                    for (auto app_el : app[el]) {
                        next_to_proc.push(app_el);
                    }
                } else {
                    a.emplace_back(el);
                }
            }
            to_proc = next_to_proc;
            if (last_el > -1) a.emplace_back(last_el);
        }

        cout << k << "\n";
        for (auto a_el : a) {
            cout << a_el << " ";
        }
        cout << "\n";
    }
}