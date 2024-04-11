#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    string s, t;
    cin >> n >> s >> t;

    vector< vector<int> > d(26, vector<int>(26, -1));

    int distance = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            distance++;
            d[s[i] - 'a'][t[i] - 'a'] = i;
        }
    }

    int result = distance;
    int a = -1, b = -1;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (d[i][j] == -1) continue;
            if (d[j][i] != -1) {
                cout << distance - 2 << '\n';
                cout << d[i][j] + 1 << ' ' << d[j][i] + 1 << '\n';
                return 0;
            }
            for (int k = 0; k < 26; k++) {
                if (d[j][k] != -1) {
                    result = distance - 1;
                    a = d[i][j] + 1; b = d[j][k] + 1;
                }
            }
        }
    }

    cout << result << endl;
    cout << a << ' ' << b << endl;
}