#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string s(n, '.');
    vector<string> output(4, s);
    bool b = false;
    if (k == 1) {
        b = true;
        output[1][n/2] = '#';
    } else if (k % 2 == 0) {
        b = true;
        for (int i = 0; i < k / 2; i++) {
            output[1][i + 1] = '#';
            output[2][i + 1] = '#';
        }
    } else if (k <= n - 2) {
        b = true;
        int left = (n - k) / 2;
        for (int i = 0; i < k; i++) {
            output[1][left + i] = '#';
        }
    } else if (k >= 4) {
        b = true;
        k++;
        for (int i = 0; i < k / 2; i++) {
            output[1][i + 1] = '#';
            output[2][i + 1] = '#';
        }
        output[1][2] = '.';
    }

    if (b) {
        cout << "YES" << '\n';
        for (auto s : output)
            cout << s << '\n';
    } else {
        cout << "NO" << '\n';
    }
}