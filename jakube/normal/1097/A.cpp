#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x;
    cin >> x;
    
    vector<string> v(5);
    for (auto& y : v)
        cin >> y;
    
    bool possible = false;
    for (auto y : v) {
        possible |=  x[0] == y[0] || x[1] == y[1];
    }
    cout << (possible ? "YES" : "NO") << '\n';
}