#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <deque>
#include <unordered_map>
using namespace std;

vector<unordered_set<int>> graph;
unordered_set<int> deg;
int resType;
deque<int> elements;


void solve(int k, int maxK) {
    if (k == 1) {
        resType = 1;
        elements.push_back(*deg.begin());
        return;
    } else if (k == 2) {
        resType = 1;
        elements.push_back(*deg.begin());
        return;
    }
    if (deg.size() > 0) {
        auto el = *deg.begin();
        deg.erase(el);
        for (auto v : graph[el]) {
            for (auto u : graph[v]) {
                if (u != el) {
                    graph[u].erase(v);
                    if (graph[u].size() <= 1) deg.insert(u);
                }
            }
            graph[v] = unordered_set<int>();
            deg.erase(v);
        }
        graph[el] = unordered_set<int>();
        solve(k - 2, maxK);
        if (resType == 1) {
            elements.push_back(el);
        }
    } else {
        int firstEl;
        for (int i = 0; i < maxK; i++) {
            if (graph[i].size() > 0) {
                firstEl = i;
                break;
            }
        }
        int currValue = 0;
        unordered_map<int, int> visited;
        vector<int> cycle;
        cycle.push_back(firstEl);
        while (true) {
            int n = cycle.size();
            int v = cycle[n - 1];
            visited[v] = currValue;
            currValue++;
            for (auto u : graph[v]) {
                if (visited.find(u) != visited.end() && visited[u] <  visited[v] - 1) {
                    resType = 2;
                    vector<int> cycleEls(maxK, -1);
                    for (auto el : visited) {
                        cycleEls[el.second] = el.first;
                    }
                    for (int val = visited[u]; val <= visited[v]; val++) {
                        elements.push_back(cycleEls[val]);
                    }
                    return;
                }
            }

            for (auto u : graph[v]) {
                if (visited.find(u) == visited.end()) {
                    cycle.push_back(u);
                    break;
                }
            }
        }
    }
}

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        graph.push_back(unordered_set<int>());
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u <= k && v <= k) {
            graph[u - 1].insert(v - 1);
            graph[v - 1].insert(u - 1);
        }
    }

    for (int i = 0; i < k; i++) {
        if (graph[i].size() <= 1) deg.insert(i);
    }

    solve(k, k);
    cout << resType << "\n";
    if (resType == 1) {
        for (int i = 0; i < (k + 1) / 2; i++) {
            cout << elements[i] + 1 << " ";
        }
    } else {
        cout << elements.size() << "\n";
        for (auto el : elements) {
            cout << el + 1 << " ";
        }
    }
}