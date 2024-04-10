#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++) {
        cout << i % 2;
    }
    cout << endl;
    
}