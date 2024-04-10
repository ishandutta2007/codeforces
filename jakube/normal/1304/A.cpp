#include <bits/stdc++.h>
using namespace std;

int solve() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int k = (x - y) / (-b - a);
    if (x + a * k == y - b * k)
        return k;
    else
        return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << solve() << '\n';
    }
}