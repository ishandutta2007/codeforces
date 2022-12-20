#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 1;
const long long mod = 1e9 + 7;

int a[N], b[N];
long long n, k;


int main() {
    int i, j;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if (k * (k - 1) < n) {
        cout << "NO";
        return 0;
    } else {
        int top = 0;
        for (i = 1; i <= k && top < n; ++i)
        for (j = i + 1; j <= k && top < n; ++j) {
            ++top;
            a[top] = i;
            b[top] = j;
            ++top;
            a[top] = j;
            b[top] = i;
        }
    }
    cout << "YES\n";
    for (i = 2; i <= n; ++i)
    if (a[i] == a[i - 1] || b[i] == b[i - 1])
        swap(a[i], b[i]);
    for (i = 1; i <= n; ++i)
        cout << a[i] << ' ' << b[i] << "\n";
}