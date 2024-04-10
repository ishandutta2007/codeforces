#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mod = n % 4;
    cout << (mod == 1 || mod == 2) << endl;
    cout << n / 2;
    if (mod == 2)
        cout << " " << 1;
    if (mod == 3)
        cout << " " << 3;
    for (int i = 1; i <= (n - mod) / 2; i += 2) {
        cout << " " << i + mod << " " << n - i + 1;
    }
    cout << endl;
}