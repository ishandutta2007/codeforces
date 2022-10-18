#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n;
    vector<int> best(8, 5'000'000);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        string s;
        cin >> s;
        int mask = 0;
        for (char ch : s)
            mask |= 1 << (ch - 'A');
        best[mask] = min(best[mask], c);
    }
    best[0] = 0;

    int res = 5'000'000;
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
            for (int c = 0; c < 8; c++) {
                if ((a | b | c) == 7)
                    res = min(res, best[a] + best[b] + best[c]);
            }
        }
    }
    
    if (res == 5'000'000)
        cout << -1 << '\n';
    else
        cout << res << '\n';
}