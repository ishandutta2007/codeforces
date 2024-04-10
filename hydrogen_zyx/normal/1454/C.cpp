#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        n = unique(a + 1, a + 1 + n) - a - 1;
        map<int, int> m;
        for (int i = 2; i < n; i++) m[a[i]]++;
        int mmin = inf;
        for (auto x:m) {
            mmin = min(mmin, x.second + 1);
        }
        if (m[a[1]] == 0) mmin = 1;
        if (m[a[n]] == 0) mmin = 1;
        if (n == 1) mmin = 0;
        cout << mmin << endl;
    }
}