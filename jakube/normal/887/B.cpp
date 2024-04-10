#include <bits/stdc++.h>
using namespace std;

set<int> s;

vector<set<int>> v;

void f(int i, int n, int x) {
    s.insert(x);

    if (i == n) {
        return;
    }

    for (int z : v[i]) {
        f(i+1, n, x*10+z);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    v.resize(3);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            int x;
            cin >> x;
            v[i].insert(x);
        }
    }

    auto w = v;
    
    f(0, n, 0);
    v = { w[0], w[2], w[1] };
    f(0, n, 0);
    v = { w[1], w[0], w[2] };
    f(0, n, 0);
    v = { w[1], w[2], w[0] };
    f(0, n, 0);
    v = { w[2], w[0], w[1] };
    f(0, n, 0);
    v = { w[2], w[1], w[0] };
    f(0, n, 0);

    for (int i = 1; i < 99999; i++) {
        if (!s.count(i)) {
            cout << i - 1 << endl;
            return 0;
        }
    }
}