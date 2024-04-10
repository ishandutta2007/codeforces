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
    
    map<long long, set<int>> m;
    for (int i = 0; i < n; i++) {
        m[v[i]].insert(i);
    }

    vector<long long> result(n, -1);
    for (auto& mm : m) {
        auto& s = mm.second;
        int par = 0;
        int last;
        for (int idx : s) {
            if (par == 0) {
                last = idx;
            } else {
                m[2*mm.first].insert(idx);
            }
            par ^= 1;
        }
        if (par)
            result[last] = mm.first;
    }

    vector<long long> res;
    for (auto x : result) {
        if (x > 0)
            res.push_back(x);
    }

    cout << res.size() << endl;
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << endl;
}