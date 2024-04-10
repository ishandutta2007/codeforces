#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> pos(n);
    int idx = 0;
    for (auto& x : v) {
        cin >> x;
        x--;
        pos[x] = idx++;
    }

    string ans(n, 'B');

    for (int x = n - 2; x >= 0; x--) {
        for (int y = pos[x]; y >= 0; y -= x + 1) {
            if (v[y] > x && ans[y] == 'B')
                ans[pos[x]] = 'A';
        }
        for (int y = pos[x]; y < n; y += x + 1) {
            if (v[y] > x && ans[y] == 'B')
                ans[pos[x]] = 'A';
        }
    }

    cout << ans << endl;
}