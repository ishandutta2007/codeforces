#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> c = {1}, d = {2};
    int tmp = 4;
    while ((int) c.size() < n - 1) {
        auto C = c;
        c.push_back(tmp);
        tmp *= 2;
        for (auto x : C) {
            c.push_back(x);
        }
        auto D = d;
        d.push_back(tmp);
        tmp *= 2;
        for (auto x : D) {
            d.push_back(x);
        }
    }
    c.resize(n - 1);
    d.resize(n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n; j++) {
            cout << d[j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }
    int x = 0, y = 0;
    while (k--) {
        int z;
        cin >> z;
        int l = 0, r = 0;
        for (auto x : c) {
            if ((z & x)) {
                l |= x;
            }
        }
        for (auto x : d) {
            if ((z & x)) {
                r |= x;
            }
        }
        for (int x2 = 0; x2 < n; x2++) {
            int res = 0;
            for (int i = min(x, x2); i < max(x, x2); i++) {
                res ^= c[i];
            }
            if (res == l) {
                x = x2;
                break;
            }
        }
        for (int y2 = 0; y2 < n; y2++) {
            int res = 0;
            for (int i = min(y, y2); i < max(y, y2); i++) {
                res ^= d[i];
            }
            if (res == r) {
                y = y2;
                break;
            }
        }
        cout << x + 1 << " " << y + 1 << endl;
    }
}