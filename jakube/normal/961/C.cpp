#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<string>> v(4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            v[i].push_back(s);
        }
    }

    int best = n*n*4;
    sort(v.begin(), v.end());
    do {
        vector<string> s;
        for (int i = 0; i < n; i++)
            s.push_back(v[0][i] + v[1][i]);
        for (int i = 0; i < n; i++)
            s.push_back(v[2][i] + v[3][i]);
        
        int correct = 0;
        for (int i = 0; i < 2*n; i++) {
            for (int j = 0; j < 2*n; j++) {
                int cell = s[i][j] - '0';
                if (cell == (i + j) % 2)
                    correct++;
            }
        }
        int b = min(correct, n*n*4 - correct);
        best = min(best, b);
    } while (next_permutation(v.begin(), v.end()));

    cout << best << endl;
}