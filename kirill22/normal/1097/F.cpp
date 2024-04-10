#include<bits/stdc++.h>

using namespace std;

const int N = 7022;
using bit = bitset<N>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> ban(N);
    for (int x = 2; x * x < N; x++) {
        for (int y = x * x; y < N; y += x * x) {
            ban[y] = 1;
        }
    }
    int n, q;
    cin >> n >> q;
    vector<bit> a(n);
    vector<bit> d(N), d2(N);
    for (int x = 1; x < N; x++) {
        for (int y = 1; y <= x; y++) {
            if (x % y == 0) {
                d[x][y] = 1;
                if (!ban[x / y]) {
                    d2[y][x] = 1;
                }
            }
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            a[i] = d[x];
        }
        if (t == 2) {
            int i, j, k;
            cin >> k >> i >> j;
            k--, i--, j--;
            a[k] = a[i] ^ a[j];
        }
        if (t == 3) {
            int i, j, k;
            cin >> k >> i >> j;
            k--, i--, j--;
            a[k] = a[i] & a[j];
        }
        if (t == 4) {
            int i, x;
            cin >> i >> x;
            i--;
            cout << (a[i] & d2[x]).count() % 2;
        }
    }
}