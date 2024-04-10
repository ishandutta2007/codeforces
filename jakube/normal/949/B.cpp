#include <bits/stdc++.h>
using namespace std;

long long n;

long long g(long long x) {
    if (x & 1)
        return (x + 1) / 2;
    return g(n + x - x / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        long long x;
        cin >> x;
        cout << g(x) << '\n';
    }
}