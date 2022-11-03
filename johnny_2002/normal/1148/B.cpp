#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int inf = 2e9 + 10;
int n, m, ta, tb, k;
int a[2][N];
int b[N];
int f[N][2];


bool check(int mid) {
    
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> ta >> tb >> k;
    for(int i = 1; i <= n; i++) cin >> a[0][i];
    for(int i = 1; i <= m; i++) {
        cin >> a[1][i];
        if (a[1][i] < a[0][i] + ta) 
            i--, m--;
    } 
    a[1][m + 1] = inf;

    for(int i = 1, j = 1; i <= n; i++) {
        while (a[0][i] + ta > a[1][j]) j++;
        b[j]++;
    }
    for(int i = 1; i <= m; i++) {
        f[i][0] = f[i - 1][0] + b[i]; 
        f[i][1] = min(f[i - 1][1], f[i - 1][0]) + 1;
        //cout << f[i][0] << " " << f[i][1] << '\n';
        if (min(f[i][0], f[i][1]) > k) {
            cout << a[1][i] + tb;
            return 0;
        }
    }
    cout << "-1";






}