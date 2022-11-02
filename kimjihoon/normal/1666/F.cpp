#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long md = 998244353;
const int M = 5002;
int c[5009];
long long cb[5009][5009], d[5009][2509];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cb[0][0] = 1;
    for (int i = 1; i <= M; i++)
        for (int j = 0; j <= M; j++) {
            cb[i][j] = cb[i - 1][j];
            if (j) cb[i][j] = (cb[i][j] + cb[i - 1][j - 1]) % md;
        }
    int tc; cin >> tc;
    for (int ti = 0; ti < tc; ti++) {
        int n; cin >> n;
        int rn = n / 2;
        for (int i = 1; i <= n; i++)
            c[i] = 0;
        v.clear(); v.push_back(0);
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            c[a]++;
        }
        for (int i = n; i >= 1; i--)
            if (c[i])
                v.push_back(c[i]);
        n = v.size(); n--;
        if (v[1] > 1) {
            cout << 0 << '\n';
            continue;
        }
        int sc = 1;
        d[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= rn; j++) {
                d[i][j] = 0;
                int t = 2 * j - 3 - sc;
                if (j == rn) {
                    if (t + 3 >= v[i]) d[i][j] = (d[i][j] + d[i - 1][j] * cb[t + 3][v[i]]) % md;
                }
                else {
                    if (t + 2 >= v[i]) d[i][j] = (d[i][j] + d[i - 1][j] * cb[t + 2][v[i]]) % md;
                }
                if (t >= v[i] - 1) d[i][j] = (d[i][j] + d[i - 1][j - 1] * cb[t][v[i] - 1]) % md;
            }
            sc += v[i];
        }
        cout << d[n][rn] << '\n';
    }
    return 0;
}