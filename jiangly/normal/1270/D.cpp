#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 1; i <= k + 1; ++i) {
        cout << "?";
        for (int j = 1; j <= k + 1; ++j)
            if (i != j)
                cout << " " << j;
        cout << endl;
        int x, y;
        cin >> x >> y;
        ++cnt[y];
    }
    cout << "! " << k + 1 - cnt.begin() -> second << endl;
    return 0;
}