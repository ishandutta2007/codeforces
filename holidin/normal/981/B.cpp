#include <bits/stdc++.h>
using namespace std;

map <int, int> m;

int main() {
    int i, j, n, a, b;
    long long ans = 0;
    bool flag = false, flag1 = false;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        m[a] = b;
        ans += b;
    }
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        ans -= m[a];
        m[a] = max(m[a], b);
        ans += m[a];
    }
    cout << ans;
}