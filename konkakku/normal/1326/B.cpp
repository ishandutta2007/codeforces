#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, x, mx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cout << mx + x << ' ';
        mx = max(mx, mx + x);
    }
}