#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    set<int> f;
    for (int d = 0; d <= 20; ++d) {
        int r = (1 << (d + 1)) - 1;
        for (int a = d - 1; a >= 0; a -= 2) r += (1 << a);
        f.insert(r), f.insert(r + 1);
    }
    cout << bool(f.count(n)) << '\n';
    return 0;
}