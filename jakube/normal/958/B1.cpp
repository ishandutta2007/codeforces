#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x-1]++;
        cnt[y-1]++;
    }
    int res = 0;
    for (int x : cnt)
        res += x == 1;
    cout << res << '\n';
}