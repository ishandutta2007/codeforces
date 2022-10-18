#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<bool> visited;

int dfs(int v) {
    if (visited[v])
        return 0;
    visited[v] = true;
    return 1 + dfs(p[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    visited.assign(n, false);
    vector<int> cycles;
    for (int i = 0; i < n; i++) {
        cycles.push_back(dfs(i));
    } 

    sort(cycles.begin(), cycles.end());
    reverse(cycles.begin(), cycles.end());
    if (n > 1) {
        cycles.push_back(cycles[0] + cycles[1]);
        cycles.erase(cycles.begin());
        cycles.erase(cycles.begin());
    } 

    long long ans = 0;
    for (auto i : cycles) 
        ans += (long long)i * i;
    cout << ans << endl;

    

}