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
    vector<int> group(256, -1);
    for (int x : v) {
        if (group[x] < 0) {
            int y = max(0, x - k + 1);
            while (group[y] >= 0 && group[y] != y) {
                y++;
            }
            for (int z = y; z <= x; z++)
                group[z] = y;
        }
        cout << group[x] << ' ';
    }
    cout << '\n';
}