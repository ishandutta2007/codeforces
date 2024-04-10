#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    
    int n;
    cin >> n;
    
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int k = a; k < b+1; k++) {
            m[{r, k}] = -1;
        }
    }
    
    deque<pair<int, int>> q;
    q.push_back({x0, y0});
    m[{x0, y0}] = 0;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop_front();

        for (int X = x-1; X <= x+1; X++) {
            for (int Y = y-1; Y <= y+1; Y++) {
                if (m.count({X, Y}) && m[{X, Y}] == -1) {
                    if (X == x1 && Y == y1) {
                        cout << m[{x, y}] + 1 << endl;
                        return 0;
                    }
                    m[{X, Y}] = m[{x, y}] + 1;
                    q.push_back({X, Y});
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}