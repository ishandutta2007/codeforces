#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string a, b;
    cin >> n >> a >> b;
    int xi = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'a') {
            xi++;
        }
        if (b[i] == 'a') {
            xi++;
        }
    }
    if (xi % 2 == 1) {
        cout << -1;
        return 0;
    }
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'a' && b[i] == 'b') {
            x.push_back(i);
        }
        if (a[i] == 'b' && b[i] == 'a') {
            y.push_back(i);
        }
    }
    int x2 = x.size(), y2 = y.size();
    if (x2 % 2 == 0 && y2 % 2 == 0) {
        cout << (x2 + y2) / 2 << endl;
        for (int i = 0; i < x2; i += 2) {
            cout << x[i] + 1 << " " << x[i + 1] + 1 << endl;
        }
        for (int i = 0; i < y2; i += 2) {
            cout << y[i] + 1 << " " << y[i + 1] + 1 << endl;
        }
    }
    else if (x2 % 2 == 1 && y2 % 2 == 1) {
        int t = x[x2 - 1];
        x.pop_back();
        x2--;
        y.push_back(t);
        y2++;
        cout << (x2 + y2) / 2 + 1 << endl;
        cout  << t + 1 << " " << t + 1 << endl;
        for (int i = 0; i < x2; i += 2) {
            cout << x[i] + 1 << " " << x[i + 1] + 1 << endl;
        }
        for (int i = 0; i < y2; i += 2) {
            cout << y[i] + 1 << " " << y[i + 1] + 1 << endl;
        }
    }
    else {
        cout << -1;
    }
}