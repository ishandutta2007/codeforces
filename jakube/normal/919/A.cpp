#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    double res = 1e18;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        double x = m * a / b;
        res = min(res, x);
    }
    std::cout << std::fixed << std::setprecision(9);
    cout << res << '\n';
}