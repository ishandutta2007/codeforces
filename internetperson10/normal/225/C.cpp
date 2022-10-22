#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int lastb[1001][1001];
int lastw[1001][1001];

const int BIG = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> b(m), w(m);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '.') w[j]++;
            else b[j]++;
        }
    }
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            lastb[i][j] = lastw[i][j] = BIG;
        }
    }
    lastb[0][1] = b[0];
    lastw[0][1] = w[0];
    for(int i = 1; i < m; i++) {
        for(int j = x; j <= y; j++) {
            lastb[i][1] = min(lastb[i][1], lastw[i-1][j] + b[i]);
            lastw[i][1] = min(lastw[i][1], lastb[i-1][j] + w[i]);
        }
        for(int j = 2; j <= y; j++) {
            lastb[i][j] = min(lastb[i][j], lastb[i-1][j-1] + b[i]);
            lastw[i][j] = min(lastw[i][j], lastw[i-1][j-1] + w[i]);
        }
    }
    int ans = BIG;
    for(int j = x; j <= y; j++) {
        ans = min(ans, lastb[m-1][j]);
        ans = min(ans, lastw[m-1][j]);
    }
    cout << ans << '\n';
}