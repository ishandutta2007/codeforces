#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    reverse(v.begin(), v.end());
    
    for (auto p : v) {
        if (p.second % 2 == 1) {
            cout << "Conan" << '\n';
            return 0;
        }
    }
    cout << "Agasa" << '\n';
    
}