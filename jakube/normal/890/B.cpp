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
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[v[i]] = i;
    }

    int last = v[0];
    for (auto p : m) {
        if (m[last] > p.second) 
            last = p.first;
    }
    cout << last << endl;
}