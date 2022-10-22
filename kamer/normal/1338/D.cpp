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
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        neighs[a - 1].push_back(b - 1);
        neighs[b - 1].push_back(a - 1);
    }

    vector<bool> vis(n, false);
    vector<int> p(n, 0);
    queue<int> toVisit;
    toVisit.push(0);
    while (!toVisit.empty()) {
        int v = toVisit.front();
        toVisit.pop();
        if (!vis[v]) {
            vis[v] = true;
            for (auto u : neighs[v]) {
                if (u != p[v]) {
                    toVisit.push(u);
                    p[u] = v;
                }
            }
        }
    }

    //for (int i = 0; i < n; i++) {
    //    cout << p[i] << " ";
    //}
    //cout << "\n";

    vector<int> bfsOrder(n, 0);
    int currIndex = 0;
    int pushIndex = 1;
    while (currIndex < n) {
        int v = bfsOrder[currIndex];
        for (auto u : neighs[v]) {
            if (u != p[v]) {
                //cout << v << " " << u << " " << pushIndex << "\n";
                bfsOrder[pushIndex] = u;
                pushIndex++;
            }
        }
        currIndex++;
    }

    vector<int> max0(n, 0);
    vector<int> max1(n, 0);
    int globalMax = 0;

    for (int i = n - 1; i >= 0; i--) {
        int v = bfsOrder[i];
        int max00 = 0, max01 = 0, max10 = 0, max11 = 0;
        int degv = 0;
        for (auto u : neighs[v]) {
            if (u != p[v]) {
                degv++;
                if (max0[u] >= max00) {
                    max01 = max00, max00 = max0[u];
                } else if (max0[u] >= max01) {
                    max01 = max0[u];
                }

                if (max(max0[u], max1[u]) >= max10) {
                    max11 = max10;
                    max10 = max(max0[u], max1[u]);
                } else if (max(max0[u], max1[u]) >= max11) {
                    max11 = max(max0[u], max1[u]);
                }
            }
        }
        max0[v] = max10 + max(degv - 1, 0);
        max1[v] = 1 + max00;
        globalMax = max(globalMax, 1 + max00 + max01);
        if (v == 0) {
            globalMax = max(globalMax, max10 + max11 + max(degv - 2, 0));
        } else {
            globalMax = max(globalMax, max10 + max11 + max(degv - 1, 0));
        }
    }

    cout << globalMax << "\n";
}