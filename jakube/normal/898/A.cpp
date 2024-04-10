#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n % 10 <= 5)
        cout << n - n % 10 << '\n';
    else
        cout << n + 10 - n % 10 << '\n';
}