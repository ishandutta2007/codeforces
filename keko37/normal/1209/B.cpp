#include<bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, sol;
bool p[MAXN][MAXN * 10];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        p[i][0] = (c == '1');
    }
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = b; j <= 1000; j += a) {
            p[i][j] ^= 1;
        }
    }
    for (int i=0; i<1000; i++) {
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (i > 0) p[j][i] ^= p[j][i-1];
            cnt += p[j][i];
        }
        sol = max(sol, cnt);
    }
    cout << sol;
    return 0;
}