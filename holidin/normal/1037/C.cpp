#include <bits/stdc++.h>
using namespace std;
const int N = 20000;

int main() {
    string a, b;
    int i, j, n, s, ans = 0;
    vector <int> v;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> a >> b;
    i = 0;
    while (i < n) {
        if (i < n - 1)
            if (a[i] != b[i] && a[i + 1] != b[i + 1] && a[i + 1] == b[i] && a[i] == b[i + 1]) {
                ++ans;
                swap(a[i], a[i + 1]);
            }
        if (a[i] != b[i])
            ++ans;
        ++i;
    }
    cout << ans;

}