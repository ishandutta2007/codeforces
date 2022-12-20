#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1;

int a[N], p[N];

int main() {
    int i, j, n, cnt = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (i = 1; i <= n; ++i)
    if (p[i] != i) {
        ++cnt;
        int x = p[i];
        a[p[i]] = a[i];
        p[a[i]] = x;
        p[i] = i;
        a[i] = i;
    }
    if (cnt % 2 == n % 2)
        cout << "Petr";
    else
        cout << "Um_nik";
}