#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(5));
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < 5; j += 1) cin >> v[i][j];
        int m = 0;
        for (int i = 1; i < n; i += 1) {
            int k = 0;
            for (int j = 0; j < 5; j += 1) k += v[i][j] < v[m][j];
            if (k >= 3) m = i;
        }
        int ok = 1;
        for (int i = 0; i < n; i += 1) {
            int k = 0;
            for (int j = 0; j < 5; j += 1) k += v[i][j] < v[m][j];
            if (k >= 3) {
                ok = 0;
            }
        }
        cout << (ok ? m + 1 : -1) << "\n";
    }
    return 0;
}