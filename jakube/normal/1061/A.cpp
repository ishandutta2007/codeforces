#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, S;
    cin >> n >> S;
    int best = S;
    for (int i = 1; i <= n; i++) {
        best = min(best, (S + i - 1) / i);
    }
    cout << best << '\n';
}