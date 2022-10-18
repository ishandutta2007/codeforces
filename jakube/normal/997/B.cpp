#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> m(49, 100);
    for (int V = 0; V < 50; V++) {
        for (int X = 0; X < 50; X++) {
            int val = (V*4 + X*9) % 49;
            m[val] = min(m[val], X + V);
        }
    }

    long long res = 0;
    for (int i = 0; i < 49; i++) {
        if (m[i] <= n)
            res += n - m[i] + 1;
    }
    cout << res << '\n';
}