#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= m;
    }

    vector<int> a, b;
    a.push_back(0);
    for (int i = 0; i < n/2; i++) {
        for (int x : a) {
            b.push_back(x);
            b.push_back((x + v[i]) % m);
        }
        a = b;
        b.clear();
    }
    
    vector<int> c, d;
    c.push_back(0);
    for (int i = n/2; i < n; i++) {
        for (int x : c) {
            d.push_back(x);
            d.push_back((x + v[i]) % m);
        }
        c = d;
        d.clear();
    }

    sort(c.begin(), c.end());
    sort(a.begin(), a.end());
    int best = 0;
    int i = c.size() - 1;
    for (int x : a) {
        while (i >= 0 && x + c[i] >= m)
            i--;
        best = max(best, x + c[i]);
    }
    cout << best << endl;
}