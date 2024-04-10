#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define N 1010
int ans[N];

int query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int sum;
    cin >> sum;
    return sum;
}

int main() {
    int n; cin >> n;
    int total = query(1, n);
    for(int i = 1; i < n - 1; ++i) {
        int new_total = query(i + 1, n);
        ans[i] = total - new_total;
        total = new_total;
    }
    int all_but_last = query(1, n - 1);
    ans[n - 1] = all_but_last - accumulate(ans + 1, ans + n - 1, 0);
    ans[n] = total - ans[n - 1];
    cout << '!';
    for(int i = 1; i <= n; ++i) cout << ' ' << ans[i];
    cout << '\n';
}