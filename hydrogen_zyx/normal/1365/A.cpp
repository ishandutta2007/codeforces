#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> x, y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                if (a) {
                    x.insert(i);
                    y.insert(j);
                }
            }
        }
        if ((min(n - x.size(), m - y.size())) & 1) {
            cout << "Ashish" << endl;
        } else
            cout << "Vivek" << endl;
    }
}