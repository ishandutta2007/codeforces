#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long mod = 1e9 + 9;
const int N = 3e5 + 1;

int a[N], x[N];

int main() {
    int i, j, k, n, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    vector <int> ans;
    for (i = 1; i <= n; ++i) {
        bool can = true;
        for (j = 0; j < i; ++j)
            x[j] = a[j + 1] - a[j];
        for (j = 1; j <= n; ++j)
        if (a[j] != x[(j - 1) % i] + a[j - 1])
            can = false;
        if (can)
            ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
}