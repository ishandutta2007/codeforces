#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int N = 1000;

int i, j, a, b;

void als(int l, int r, int k) {
    if (a < (l + r) / 2 && (l + r)/2 <= b) {
        if (k == j)
            cout << "Final!";
        else
            cout << k;
        exit(0);
    }
    if (r - l > 1) {
        als(l, (l + r)/2, k - 1);
        als((l + r)/2, r, k - 1);
    }
}

int main() {
    int c, d, n;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    i = 1, j = 0;
    while (i < n) {
        i *= 2;
        ++j;
    }
    if (b < a)
        swap(a, b);
    als(1, n + 1, j);

}