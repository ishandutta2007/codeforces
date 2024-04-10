#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int idx = 0; idx < n; idx++)
        cin >> s[idx];
    
    vector<int> number(n, 100000);
    vector<int> letter(n, 100000);
    vector<int> symbol(n, 100000);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            char c = s[i][j];
            if (c == '#' || c == '*' || c== '&') {
                symbol[i] = min(symbol[i], min(j, m - j));
            } else if (c >= '0' && c <= '9') {
                number[i] = min(number[i], min(j, m - j));
            } else if (c >= 'a' && c <= 'z') {
                letter[i] = min(letter[i], min(j, m - j));
            }
        }
    }

    int best = 1000000;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b) continue;
            for (int c = 0; c < n; c++) {
                if (a == c || b == c) continue;
                best = min(best, letter[a] + number[b] + symbol[c]);
            }
        }
    }

    cout << best << endl;

    return 0;
}