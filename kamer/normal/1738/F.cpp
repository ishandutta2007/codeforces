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
        vector<tuple<int, int>> d(n);
        for (int i = 0; i < n; i++) {
            int d_el;
            cin >> d_el;
            d[i] = { d_el, i };
        }
        sort(d.rbegin(), d.rend());

        vector<vector<int>> comp(n, vector<int>());
        vector<int> color(n, -1);
        int curr_color = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            auto [dv, v] = d[i];
            if (vis[v]) continue;
            vis[v] = true;
            color[v] = curr_color;
            comp[curr_color].push_back(v);
            bool exist_comp = false;
            for (int i = 0; i < dv; i++) {
                cout << "? " << v + 1 << "\n";
                cout.flush();
                int u;
                cin >> u;
                u--;
                vis[u] = true;
                if (color[u] != -1) {
                    exist_comp = true;
                    for (auto w : comp[curr_color]) {
                        comp[color[u]].emplace_back(w);
                        color[w] = color[u];
                    }
                    comp[curr_color] = vector<int>();
                    break;
                } else {
                    color[u] = curr_color;
                    comp[curr_color].emplace_back(u);
                }
            }

            if (!exist_comp) {
                curr_color++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = curr_color++;
            }
        }

        cout << "!";
        for (auto c : color) {
            cout << " " << c + 1;
        }
        cout << "\n";
        cout.flush();
    }
}