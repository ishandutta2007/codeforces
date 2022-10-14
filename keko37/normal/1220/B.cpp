#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1005;

int n;
llint a[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    llint p = sqrt(a[0][1] * a[0][n-1] / a[1][n-1]);
    cout << p << " ";
    for (int i=1; i<n; i++) {
        cout << a[0][i] / p << " ";
    }
    return 0;
}