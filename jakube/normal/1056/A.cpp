#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    set<int> s;
    for (int i = 0; i < n; i++) {
        set<int> t;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (i == 0 || s.count(x))
                t.insert(x);
        }
        s = t;
    }
    for (auto x : s) {
        cout << x << ' ';
    }
    cout << '\n';
}