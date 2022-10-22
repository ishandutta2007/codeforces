#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

void dfs(int t, vector<vector<int>>& graph, vector<int>& parents) {
    queue<int> toProcess;
    toProcess.push(t);
    while (!toProcess.empty()) {
        int v = toProcess.front();
        toProcess.pop();
        for (auto u : graph[v]) {
            if (u != parents[v]) {
                parents[u] = v;
                toProcess.push(u);
            }
        }
    }
}

void findDiameters(int t, vector<vector<int>>& graph, vector<int>& parent, vector<int>& tDiameters) {
    for (int u : graph[t]) {
        if (u != parent[t]) {
            findDiameters(u, graph, parent, tDiameters);
            tDiameters[t] = max(tDiameters[t], tDiameters[u] + 1);
        }
    }
}

void fillPossible(int r, int forbidden, vector<vector<int>>& graph, vector<bool>& possible, vector<int>& parents) {
    queue<int> toProcess;
    toProcess.push(r);
    while (!toProcess.empty()) {
        int v = toProcess.front();
        toProcess.pop();
        possible[v] = true;
        for (auto u : graph[v]) {
            if (u != forbidden && u != parents[v]) {
                toProcess.push(u);
            }
        }
    }
}

void finishDiameters(int v, vector<vector<int>>& graph, vector<int>& vParents, vector<int>& vDiameters, vector<unordered_map<int, int>>& diameters) {
    int maxim = -1, maxVertex = -1, secondMax = -1, secondMaxVertex = -1;
    for (auto u : graph[v]) {
        if (u != vParents[v]) {
            diameters[v][u] = vDiameters[u];
        }

        if (diameters[v][u] >= maxim) {
            secondMax = maxim;
            secondMaxVertex = maxVertex;
            maxim = diameters[v][u];
            maxVertex = u;
        } else if (diameters[v][u] > secondMax) {
            secondMax = diameters[v][u];
            secondMaxVertex = u;
        }
    }

    for (auto u : graph[v]) {
        if (u != vParents[v]) {
            if (u == maxVertex) {
                diameters[u][v] = secondMax + 1;
            } else {
                diameters[u][v] = maxim + 1;
            }
        }
    }

    for (auto u : graph[v]) {
        if (u != vParents[v]) {
            finishDiameters(u, graph, vParents, vDiameters, diameters);
        }
    }
}

void solve() {
    int n, t, h;
    cin >> n >> t >> h;
    t--, h--;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //cout << "GRAPH done\n";

    vector<int> tDiameters(n, 1), hDiameters(n, 1);
    vector<int> tParents(n, t), hParents(n, h);
    
    dfs(t, graph, tParents);
    dfs(h, graph, hParents);

    //cout << "dfs done\n";
    //for (int i = 0; i < n; i++) {
    //    cout << "tp hp " << tParents[i] << " " << hParents[i] << "\n";
    //}

    // snek is t to h
    vector<int> snek;

    int tTemp = t;
    while (tTemp != h) {
        snek.push_back(tTemp);
        tTemp = hParents[tTemp];
    }
    snek.push_back(h);

    //cout << "snek done\n";

    //for (auto s : snek) {
    //    cout << s << " ";
    //}
    //cout << "\n";

    findDiameters(t, graph, tParents, tDiameters);
    findDiameters(h, graph, hParents, hDiameters);

    //cout << "diameters done\n";

    //for (int i = 0; i < n; i++) {
    //    cout << "td hd " << tDiameters[i] << " " << hDiameters[i] << "\n";
    //}

    int tIndex = 0, hIndex = ((int)snek.size()) - 1;
    while (true) {
        int newTIndex = min(tDiameters[snek[hIndex]] - 1 - (((int)snek.size()) - 1 - hIndex), hIndex);
        int newHIndex = max(((int)snek.size()) - 1 - hDiameters[snek[tIndex]] + 1  + tIndex, tIndex);
        newTIndex = min(newTIndex, ((int)snek.size()) - 1);
        newHIndex=  max(newHIndex, 0);
        if (newTIndex == tIndex && newHIndex == hIndex) {
            break;
        }
        tIndex = newTIndex, hIndex = newHIndex;
        if (tIndex + 1 >= hIndex) {
            break;
        }
    }

    //cout << "tIndex done\n";

    vector<bool> possible(n, false);
    if (tIndex >= hIndex - 1) {
        possible = vector<bool>(n, true);
    } else {
        fillPossible(t, snek[tIndex + 1], graph, possible, tParents);
        fillPossible(h, snek[hIndex - 1], graph, possible, hParents);
    }

    //cout << "possible done\n";

    vector<unordered_map<int, int>> diameters(n, unordered_map<int, int>());
    finishDiameters(t, graph, tParents, tDiameters, diameters);
    
    //cout << "finishDiamters\n";

    bool answerYes = false;
    for (int i = 0; i < n; i++) {
        if (possible[i]) {
            int count = 0;
            for (auto it = diameters[i].begin(); it != diameters[i].end(); ++it) {
                if (it->second >= ((int)snek.size()) - 1) count++;
            }
            if (count >= 3) {
                answerYes = true;
                break;
            }
        }
    }

    //cout << "counts done\n";

    if (answerYes) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main(void) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}