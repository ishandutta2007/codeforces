#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 3E5;
int n;
string s;
int a[2 * MAX_N + 1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    s += s;
    for (int i = 0; i <= 2 * n; ++i)
        a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);
    if (a[n] != 0) {
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    int *min_pos = min_element(a, a + 2 * n + 1);
    copy(min_pos, min_pos + n + 1, a);
    int mn = a[0];
    for (int i = 0; i <= n; ++i)
        a[i] -= mn;
    int cnt0 = count(a, a + n, 0);
    tuple<int, int, int> ans {cnt0, 0, 0};
    for (int i = 1, j = 0; i <= n; ++i)
        if (a[i] == 0) {
            ans = max(ans, {count(a + j, a + i, 1), j, i - 1});
            for (int k = j + 2, l = j + 1; k < i; ++k)
                if (a[k] == 1) {
                    ans = max(ans, {count(a + l, a + k, 2) + cnt0, l, k - 1});
                    l = k;
                }
            j = i;
        }
    int x, l, r;
    tie(x, l, r) = ans;
    cout << x << endl;
    l = (l + min_pos - a) % n + 1;
    r = (r + min_pos - a) % n + 1;
    cout << l << " " << r << endl;
    return 0;
}