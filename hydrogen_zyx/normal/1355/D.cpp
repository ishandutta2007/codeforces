#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n, s;
    cin >> n >> s;
    if (n <= s / 2) {
        cout << "YES" << endl;
        for (int i = 1; i < n; i++) cout << 2 << ' ';
        cout << s - (n - 1) * 2 << endl;
        cout << 1;
    } else {
        cout << "NO";
    }
}