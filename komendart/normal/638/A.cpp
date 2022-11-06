#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a;
    cin >> n >> a;

    if (a % 2 == 1) a -= 1;
    else a = n - a;

    cout << a / 2 + 1 << '\n';
}