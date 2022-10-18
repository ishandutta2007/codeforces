#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;
    
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == s) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][1] == s[0] && v[j][0] == s[1]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}