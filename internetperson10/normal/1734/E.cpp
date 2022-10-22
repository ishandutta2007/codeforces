#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int a[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            a[i][j] = 1;
        }
    }
    int x, s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i][0];
        if(i) {
            a[i][0] -= s;
            a[i][0] -= (i * i);
            a[i][0] += n * n * n;
            a[i][0] %= n;
        }
        s += a[i][0];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) a[i][j] = a[i][j];
            else if(i == 0) a[i][j] += a[i][j-1];
            else if(j == 0) a[i][j] += a[i-1][j];
            else a[i][j] += (n + a[i][j-1] + a[i-1][j] - a[i-1][j-1]);
            a[i][j] %= n;
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}