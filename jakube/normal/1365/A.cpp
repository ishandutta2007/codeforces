#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n, m;
        cin >> n >> m;
        set<int> rows, columns;
        int x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                if (x) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        int poss = min(n - rows.size(), m - columns.size());
        if (poss % 2)
            cout << "Ashish" << '\n';
        else
            cout << "Vivek" << '\n';
            
    }
}