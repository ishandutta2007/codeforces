#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    n++;
    if (n == 1)
        cout << 0 << '\n';
    else if (n % 2)
        cout << n << '\n';
    else
        cout << n / 2 << '\n';
}