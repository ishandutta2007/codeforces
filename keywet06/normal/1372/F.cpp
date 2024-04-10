#include <bits/stdc++.h>

const int N = 200005;

int n, x, y;
int a[N];

void solve(int l, int r) {
    if (l > r) return;
    std::cout << "? " << l << ' ' << r << std::endl;
    std::cin >> x >> y;
    int cl = r - y + 1, cr = l + y - 1;
    if (cl <= cr) {
        for (int i = cl; i <= cr; ++i) a[i] = x;
        solve(l, cl - 1), solve(cr + 1, r);
    } else {
        int mid = l + r >> 1;
        solve(l, mid), solve(mid + 1, r);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    solve(1, n);
    std::cout << '!';
    for (int i = 1; i <= n; ++i) std::cout << ' ' << a[i];
    std::cout << std::endl;
    return 0;
}