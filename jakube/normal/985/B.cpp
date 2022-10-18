#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> sum(m, 0);
    for (string s : v) {
        for (int i = 0; i < m; i++) {
            sum[i] += s[i] - '0';
        }
    }

    for (string s : v) {
        bool b = true;
        for (int i = 0; i < m; i++) {
            if (sum[i] - (s[i] == '1') == 0)
                b = false;
        }
        if (b) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}