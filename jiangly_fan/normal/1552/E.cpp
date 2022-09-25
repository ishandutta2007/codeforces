#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, k;
    cin >> n >> k;
    vector<int> vv(n * k + 1);
    vector<vector<int>> w(n + 1);
    for (int i = 1; i <= n * k; i += 1) {
        cin >> vv[i];
        w[vv[i]].push_back(i);
    }
    int m = (n + k - 2) / (k - 1);
    vector<int> v(n);
    for (int i = 0; i < n; i += 1) v[i] = i + 1;
    vector<int> p(n + 1), q(n + 1);
    for (int i = 1; i < k; i += 1) {
        sort(v.begin(), v.end(), [&](const int& x, const int& y){
            return w[x][i] < w[y][i];
        });
        int mm = m;
        for (int j : v) if (not p[j]) {
            p[j] = w[j][i - 1];
            q[j] = w[j][i];
            mm -= 1;
            if (mm == 0) break;
        }
    }
    for (int i = 1; i <= n; i += 1) cout << p[i] << " " << q[i] << "\n";
    return 0;
}