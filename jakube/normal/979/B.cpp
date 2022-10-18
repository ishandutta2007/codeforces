#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    
    vector<int> c(3, 0);
    for (int i = 0; i < 3; i++) {
        vector<int> a(256, 0);
        for (char c : v[i]) {
            a[c]++;
        }
        c[i] = *max_element(a.begin(), a.end());
        if (n == 1 && c[i] == (int)v[i].size()) {
            c[i]--;
        } else {
            c[i] = min((int)v[i].size(), c[i] + n);
        }

    }

    if (c[0] > max(c[1], c[2]))
        cout << "Kuro" << '\n';
    else if (c[1] > max(c[0], c[2]))
        cout << "Shiro" << '\n';
    else if (c[2] > max(c[0], c[1]))
        cout << "Katie" << '\n';
    else
        cout << "Draw" << '\n';
}