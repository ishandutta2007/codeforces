#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = {v[i], i+1};
    }
    sort(x.begin(), x.end());
    
    set<pair<int, int>> y;
    int idx = 0;
    for (char c : s) {
        if (c == '0') {
            cout << x[idx].second << " ";
            y.insert({-x[idx].first, x[idx].second});
            idx++;
        } else {
            cout << y.begin()->second << " ";
            y.erase(y.begin());
        }
    }
    cout << '\n';
}