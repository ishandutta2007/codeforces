#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> lst(n, -1);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        if (lst[x] != -1 && (ans == -1 || ans > i - lst[x] + 1))
            ans = i - lst[x] + 1;
        lst[x] = i;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}