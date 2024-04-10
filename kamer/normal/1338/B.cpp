#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <utility>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> neighs(n, vector<int>());
    vector<int> degs(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        neighs[a - 1].push_back(b - 1);
        neighs[b - 1].push_back(a - 1);
        degs[a - 1]++;
        degs[b - 1]++;
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (degs[i] > 1) {
            root = i;
            break;
        }
    }

    vector<bool> vis(n, false);
    vector<int> h(n, 0);
    vector<int> p(n, root);
    queue<int> toVisit;
    toVisit.push(root);
    while (!toVisit.empty()) {
        int v = toVisit.front();
        toVisit.pop();
        if (!vis[v]) {
            vis[v] = true;
            for (auto u : neighs[v]) {
                if (!vis[u]) {
                    p[u] = v;
                    h[u] = h[v] + 1;
                    toVisit.push(u);
                }
            }
        }
    }

    bool hasOdd = false;
    bool hasEven = false;
    for (int i = 0; i < n; i++) {
        if (degs[i] == 1) {
            if (h[i] % 2 == 0) {
                hasEven = true;
            } else {
                hasOdd = true;
            }
        }
    }

    if (hasEven && hasOdd) {
        cout << "3 ";
    } else {
        cout << "1 ";
    }

    int maxCount = n - 1;
    vector<bool> checked(n, false);
    for (int i = 0; i < n; i++) {
        if (degs[i] == 1 && !checked[i]) {
            int par = p[i];
            for (auto u : neighs[par]) {
                if (u != p[par] && degs[u] == 1) {
                    checked[u] = true;
                    if (u != i) maxCount--;
                }
            }

        }
    }
    cout << maxCount << "\n";
}