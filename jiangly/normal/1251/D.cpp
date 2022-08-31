#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int MAX_N = 2E5;
int n;
LL s;
int l[MAX_N], r[MAX_N];
void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];
    int L = 1, R = 1E9;
    int m = (n + 1) / 2;
    LL low = accumulate(l, l + n, 0LL);
    while (L < R) {
        int x = (L + R + 1) / 2;
        vector<int> d;
        for (int i = 0; i < n; ++i)
            if (r[i] >= x)
                d.push_back(max(0, x - l[i]));
        bool ok = true;
        sort(d.begin(), d.end());
        if (d.size() >= m && accumulate(d.begin(), d.begin() + m, 0LL) + low <= s)
            L = x;
        else
            R = x - 1;
    }
    cout << L << "\n";
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