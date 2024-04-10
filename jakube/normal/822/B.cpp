#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> result;
    for (int i = 0; i < 1005; i++)
        result.push_back(1);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    
    for (int i = 0; i <= m - n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (s[j] != t[i + j]) {
                v.push_back(j);
            }
        }
        if (v.size() < result.size()) {
            result = v;
        }
    }

    cout << result.size() << endl;
    for (int i : result) {
        cout << i + 1 << " ";
    }
    cout << endl;
}