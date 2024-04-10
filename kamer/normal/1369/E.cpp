#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
        cin >> y[i];
        x[i]--;
        y[i]--;
    }
    vector<int> count(n, 0);
    vector<vector<int>> friends(n, vector<int>());
    for (int i = 0; i < m; i++) {
        count[x[i]]++;
        count[y[i]]++;
        friends[x[i]].push_back(i);
        friends[y[i]].push_back(i);
    }

    vector<int> order(m);
    vector<bool> vis(m, false);
    vector<bool> countVis(n, false);
    queue<int> goodFood;
    for (int i = 0; i < n; i++) {
        if (count[i] <= w[i]) { goodFood.push(i); countVis[i] = true; }
    }
    int currIndex = m - 1;
    while (!goodFood.empty()) {
        int currFood = goodFood.front();
        goodFood.pop();
        for (auto f : friends[currFood]) {
            if (!vis[f]) {
                vis[f] = true;
                count[x[f]]--;
                count[y[f]]--;
                if (count[x[f]] <= w[x[f]] && !countVis[x[f]]) {
                    countVis[x[f]] = true;
                    goodFood.push(x[f]);
                }
                
                if (count[y[f]] <= w[y[f]] && !countVis[y[f]]) {
                    countVis[y[f]] = true;
                    goodFood.push(y[f]);
                }
                order[currIndex] = f;
                currIndex--;
            }
        }
    }
    if (currIndex != -1) {
        cout << "DEAD\n";
    } else {
        cout << "ALIVE\n";
        for (auto f : order) {
            cout << f + 1 << " ";
        }
        cout << "\n";
    }
}