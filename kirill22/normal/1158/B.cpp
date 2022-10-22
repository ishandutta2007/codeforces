#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int p = (n - k) / 2 + 1;
    for (int i = 0; i < n; i++) {
        cout << (i % p == p - 1 ? '1' : '0');
    }
}