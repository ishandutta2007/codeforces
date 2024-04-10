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
    reverse(v.begin(), v.end());
    set<int> s;
    vector<int> res;
    for (int x : v) {
        if (s.count(x)) {

        } else {
            s.insert(x);
            res.push_back(x);
        }
    }
    reverse(res.begin(), res.end());
    cout << (int)res.size() << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
    
}