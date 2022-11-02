#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

const int N = 160;
const int B = 2;

int &add(int &a, int b) { return (a += b, a >= P) ? (a -= P) : a; }

int n, m;
int f[N][N][B][B];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int a = 1; a <= m; ++a)
        for (int b = a; b <= m; ++b) f[a][b][1][1] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long cnt = 0;
        for (int a = 1; a <= m; ++a) {
            for (int b = a; b <= m; ++b) {
                for (int ka = 0; ka <= 1; ++ka) {
                    for (int kb = 0; kb <= 1; ++kb) cnt += f[a][b][ka][kb];
                }
            }
        }
        ans = (ans + cnt * (n - i + 1)) % P;
        for (int a = 1; a <= m; ++a) {
            for (int b = a + 1; b <= m; ++b) {
                for (int kb = 0; kb <= 1; ++kb) {
                    add(f[a + 1][b][0][kb], f[a][b][0][kb]);
                    add(f[a + 1][b][0][kb], f[a][b][1][kb]);
                }
            }
        }
        for (int a = 1; a <= m; ++a) {
            for (int b = m; b >= a + 1; --b) {
                for (int ka = 0; ka <= 1; ++ka) {
                    add(f[a][b - 1][ka][0], f[a][b][ka][0]);
                    add(f[a][b - 1][ka][0], f[a][b][ka][1]);
                }
            }
        }
        for (int a = m; a >= B; --a) {
            for (int b = a; b <= m; ++b) {
                for (int kb = 0; kb <= 1; ++kb) {
                    add(f[a - 1][b][1][kb], f[a][b][1][kb]);
                }
            }
        }
        for (int a = m; a >= 1; --a) {
            for (int b = a; b <= m - 1; ++b) {
                for (int ka = 0; ka <= 1; ++ka) {
                    add(f[a][b + 1][ka][1], f[a][b][ka][1]);
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}