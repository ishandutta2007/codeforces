#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    
    vector<int> b(n);
    vector<int> cnt(n);
    map<int, vector<int>> pers;
    for (int x = 0; x < n; x++) {
        pers[n - a[x]].push_back(x);
    }
    int color = 0;
    for (auto [x, persons] : pers) {
        if ((int)persons.size() % x) {
            cout << "Impossible" << '\n';
            return 0;
        }
        int idx = 0;
        for (int y : persons) {
            if (idx % x == 0)
                color++;
            b[y] = color;
            idx++;
        }
    }

    cout << "Possible" << '\n';
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << '\n';
    
}