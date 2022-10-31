#include <bits/stdc++.h>

using namespace std;

int a[101], cnt[101];

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    
    for (int mx = 200; mx > 0; mx--) {
        int real_cnt = 0;
        for (int t = 1; t <= 100; t++) {
            real_cnt += cnt[t] / mx;
        }
        if (real_cnt >= n) {
            cout << mx;
            return 0;
        }
     }
    cout << 0;
    return 0;
}