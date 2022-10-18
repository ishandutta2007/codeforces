#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, x;
    cin >> a >> b >> x;
    x++;
    
    string s;
    if (a < b) {
        int ones = (x + 1) / 2;
        s = string(b - ones + 1, '1');
        b = ones - 1;
        x--;
    }

    int ones = x / 2;
    int zeros = (x + 1) / 2;
    s += string(a - zeros + 1, '0');
    zeros--;
    if (ones)
    s += string(b - ones + 1, '1');
    ones--;
    while (zeros > 0 || ones > 0) {
        if (zeros > 0) {
            s += '0';
            zeros--;
        }
        if (ones > 0) {
            s += '1';
            ones--;
        }
    }

    cout << s << '\n';
}