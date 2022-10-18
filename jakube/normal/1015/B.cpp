#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            bool found = false;
            for (int j = i; j + 1 < n; j++) {
                if (s[j+1] == t[i]) {
                    for (int k = j; k >= i; k--) {
                        res.push_back(k);
                        swap(s[k], s[k+1]);
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << (int)res.size() << '\n';
    for (auto x : res) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}