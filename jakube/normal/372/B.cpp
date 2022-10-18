#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> psum;
int rect(int x1, int y1, int x2, int y2) {
    return psum[x2+1][y2+1] - psum[x1][y2+1] - psum[x2+1][y1] + psum[x1][y1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, q;
    cin >> n >> m >> q;
    vector<string> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    psum.assign(n+1, vector<int>(m+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j] + (v[i][j] == '1');
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << rect(i,j,i,j);
    //     }
    //     cout << endl;
    // }
    
    vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(m+1, vector<vector<int>>(n+1, vector<int>(m+1, 0))));
    for (int a = n; a > 0; a--) {
        for (int b = m; b > 0; b--) {
            for (int c = a; c <= n; c++) {
                for (int d = b; d <= m; d++) {
                    int &r = dp[a][b][c][d];
                    if (rect(a-1, b-1, c-1, d-1) == 0)
                        r++;
                    for (int A = 0; A < 2; A++) {
                        for (int B = 0; B < 2; B++) {
                            for (int C = 0; C < 2; C++) {
                                for (int D = 0; D < 2; D++) {
                                    if (A + B + C + D && a + A <= c && b + B <= d) {
                                        if ((A + B + C + D) % 2 == 1) 
                                            r += dp[a+A][b+B][c-C][d-D];
                                        else
                                            r -= dp[a+A][b+B][c-C][d-D];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c][d] << '\n';
    }

    return 0;
}