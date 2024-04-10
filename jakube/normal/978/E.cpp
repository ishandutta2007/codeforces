#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, w;
    cin >> n >> w;
    long long L = 0;
    long long R = w;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        L += x;
        R += x;
        L = max(0LL, L);
        R = min(R, w);
    }
    if (R < L)
        cout << 0 << '\n';
    else
        cout << R + 1 - L << endl;
}