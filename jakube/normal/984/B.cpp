#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n+2);
    v[0] = v[n+1] = string(m+2, '.');
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] = "." + v[i] + ".";
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] != '*') {
                int cnt = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        cnt += v[i+x][j+y] == '*';
                    }
                }
                char c;
                if (cnt > 0)
                    c = '0' + cnt;
                else
                    c = '.';
                if (c != v[i][j]) {
                    cout << "NO" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "YES" << '\n';
}