#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 1;
set <int> s;
int a[N], b[N];
bool use[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (i = 0; i < n; ++i) {
        cin >> b[i];
    }
    j = n - 1;
    while (j > 0 && b[j - 1] + 1 == b[j] && b[j] != 1)
        --j;
    if (b[j] == 1) {
        int x = b[n - 1] + 1;
        bool can = 1;
        for (i = 0; i < j; ++i) {
            if (s.find(x) == s.end())
                can = 0;
            s.insert(b[i]);
            ++x;
        }
        if (can) {
            cout << j;
            exit(0);
        }
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2 - 1;
        s.clear();
        for (i = 0; i <= n; ++i)
            use[i] = 0;
        for (i = 0; i < n; ++i)
            use[a[i]] = 1;
        for (i = 0; i < mid; ++i)
            use[b[i]] = 1;
        bool can = 1;
        for (i = mid; i < n; ++i) {
            if (!use[i - mid + 1]) {
                can = 0;
            }
            use[b[i]] = 1;
        }
        if (can)
            r = mid + 1;
        else
            l = mid + 1;
    }
    cout << l + n;
}