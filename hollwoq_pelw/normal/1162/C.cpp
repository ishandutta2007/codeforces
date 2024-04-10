#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, x;
    cin >> n >> k;
    vector<int> first(n, k + 1), last(n, -1);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        x -= 1;
        first[x] = min(first[x], i);
        last[x] = max(last[x], i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && last[i - 1] <= first[i]) ans += 1;
        if (i < n - 1 && last[i + 1] <= first[i]) ans += 1;
        if (last[i] == -1) ans += 1;
    }
    cout << ans;
    return 0;
}