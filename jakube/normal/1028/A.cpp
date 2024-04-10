#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& x : v)
        cin >> x;
    
    int x1 = 1000, x2 = 0;
    int y1 = 1000, y2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'B') {
                x1 = min(x1, i+1);
                x2 = max(x2, i+1);
                y1 = min(y1, j+1);
                y2 = max(y2, j+1);
            }
        }
    }
    cout << (x1 + x2) / 2 << " " << (y1 + y2) / 2 << endl;
}