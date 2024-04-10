#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m = *min_element(v.begin(), v.end());
    long long cnt = 0;
    for (auto val : v) {
        if ((val - m) % k) {
            cout << -1 << endl;
            return 0;
        }
        cnt += (val - m) / k;
    }
    cout << cnt << endl;
     
}