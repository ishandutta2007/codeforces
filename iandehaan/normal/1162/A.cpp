#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, h, m;
    cin >> n >> h >> m;

    int mx[n];
    for (int i = 0; i < n; i++) {
        mx[i] = h;
    }
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int j = l-1; j < r; j++) {
            mx[j] = min(mx[j], x);
        }
    }
    int out = 0;
    for (int i = 0; i < n; i++) {
        out += mx[i]*mx[i];
    }
    cout << out << endl;
}