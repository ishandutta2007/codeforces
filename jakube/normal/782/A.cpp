#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> v[i];
    }
    
    set<int> s;
    int m = 0;
    for (int nu : v) {
        if (s.count(nu)) {
            s.erase(nu);
        } else {
            s.insert(nu);
            m = max(m, (int)s.size());
        }
    }

    cout << m << endl;

    return 0;
}