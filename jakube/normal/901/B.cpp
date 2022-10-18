#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    

    vector<int> a(1, 1), b;
    for (int i = 0; i < n; i++) {
        auto c = a;
        c.push_back(0);

        for (int j = 0; j < i; j++) {
            c[j + 2] += b[j];
            c[j + 1] %= 3;
        }

        b = a;
        a = c;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    cout << n << endl;
    for (auto x : a) {
        if (x == 2)
            cout << -1 << " ";
        else
            cout << x << " ";
    }
    cout << endl;
    cout << n - 1 << endl;
    for (auto x : b) {
        if (x == 2)
            cout << -1 << " ";
        else
            cout << x << " ";
    }
    cout << endl;
}