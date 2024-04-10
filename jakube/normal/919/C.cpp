#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    
    vector<string> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int res = 0;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '.')
                    res++;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            int last = -1;
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '*') {
                    last = j;
                }
                if (j - last >= k)
                    res++;
            }
        }
        for (int i = 0; i < m; i++) {
            int last = -1;
            for (int j = 0; j < n; j++) {
                if (c[j][i] == '*') {
                    last = j;
                }
                if (j - last >= k)
                    res++;
            }
        }
    }
    cout << res << '\n';
}