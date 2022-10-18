#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> p;

int dfs(int cur) {
    if (visited[cur]) {
        return 0;
    }

    visited[cur] = true;
    return 1 + dfs(p[cur]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    p.resize(n);
    for (int idx = 0; idx < n; idx++) {
        cin >> p[idx];
        p[idx]--;
    }

    vector<int> b(n);
    for (int idx = 0; idx < n; idx++)
        cin >> b[idx];
    
    visited.assign(n, false);
    int cycles = 0;
    for (int i = 0; i < n; i++) {
        int len = dfs(i);
        if (len) {
            cycles++;
        }
    }
    
    int result = cycles > 1 ? cycles : 0;
    if (accumulate(b.begin(), b.end(), 0) % 2 == 0) result++;

    cout << result << endl;
    return 0;
}