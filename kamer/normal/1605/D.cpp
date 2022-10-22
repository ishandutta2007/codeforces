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
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> height(n, 1);
        vector<bool> vis(n, false);
        queue<int> bfs;
        bfs.push(0);
        vis[0] = true;
        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            for (auto u : graph[v]) {
                if (!vis[u]) {
                    vis[u] = true;
                    height[u] = height[v] + 1;
                    bfs.push(u);
                }
            }
        }

        vector<int> evens, odds;
        for (int v = 0; v < n; v++) {
            if (height[v] % 2 == 0) evens.push_back(v);
            else odds.push_back(v);
        }

        vector<int> powers;
        int curr_pow = 1;
        while (curr_pow <= n) {
            powers.push_back(curr_pow);
            curr_pow *= 2;
        }

        vector<int> perm(n);

        int k = powers.size();
        for (int i = k - 1; i >= 0; i--) {
            if (evens.size() > odds.size()) {
                for (int j = powers[i]; j <= n; j++) {
                    int val = evens[evens.size() - 1];
                    evens.pop_back();
                    perm[val] = j;
                }
            } else {
                for (int j = powers[i]; j <= n; j++) {
                    int val = odds[odds.size() - 1];
                    odds.pop_back();
                    perm[val] = j;
                }
            }

            n = powers[i] - 1;
        }

        for (auto val : perm) {
            cout << val << " ";
        }
        cout << "\n";
    }
}