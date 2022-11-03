#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> last(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        last[a[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (last[a[i]] == i) {
            continue;
        }
        int cnt = 1;
        int right = last[a[i]];
        int new_right = right;
        int start = i;
        while (1) {
            for (int j = start + 1; j < right; ++j) {
                if (last[a[j]] > new_right) {
                    new_right = last[a[j]];
                }
            }
            if (new_right > right) {
                start = right;
                right = new_right;
                ++cnt;
            } else {
                break;
            }
        }
        ans += (right - i + 1) - (cnt + 1);
        i = right;
    }
    cout << ans << "\n";

}