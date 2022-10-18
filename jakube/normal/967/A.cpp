#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;
    vector<int> v(n + 2);
    v[0] = - s - 1;
    for (int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;
        v[i+1] = h * 60 + m;
    }
    v[n+1] = 29 * 60;

    for (int i = 0; i <= n; i++) {
        if (v[i] + 2 * (s + 1) <= v[i+1]) {
            int res = v[i] + s + 1;
            cout << res / 60 << " " << res % 60 << endl;
            break;
        }
    }

}