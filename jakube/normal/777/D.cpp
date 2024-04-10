#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j < v[i].size(); j++) {
            if (j < v[i+1].size() && v[i][j] < v[i+1][j]) break;
            if (j == v[i+1].size() || v[i][j] > v[i+1][j])
                v[i] = v[i].substr(0, j);
        }
    }

    for (string s : v)
        cout << s << '\n';
}