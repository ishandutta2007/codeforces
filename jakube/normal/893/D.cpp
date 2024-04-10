#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int cnt = 0;
    int d_min = 0, d_max = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            if (d_max >= 0) {
                // perfect
                d_min = max(d_min, 0);
            } else {
                d_min = 0;
                d_max = d;
                cnt++;
            }
        } else {
            d_min += v[i];
            d_max += v[i];
            d_max = min(d, d_max);
            if (d_min > d_max) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << cnt << '\n';
}