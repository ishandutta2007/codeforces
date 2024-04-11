#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

struct item {
    int a, b, id;
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<item> less, more;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            less.push_back({a, b, i + 1});
        } else {
            more.push_back({a, b, i + 1});
        }
    }
    
    if (sz(less) > sz(more)) {
        sort(begin(less), end(less), [] (item x, item y) {
            return x.a > y.a;
        });
        cout << sz(less) << '\n';
        for (auto [a, b, id]: less) {
            cout << id << ' ';
        }
        cout << '\n';
    } else {
        sort(begin(more), end(more), [] (item x, item y) {
            return x.b < y.b;
        });
        cout << sz(more) << '\n';
        for (auto [a, b, id]: more) {
            cout << id << ' ';
        }
        cout << '\n';
    }
}