#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << n * j + (j & 1 ? i : n - i - 1) + 1 << " \n"[j == n - 1];
    return 0;
}