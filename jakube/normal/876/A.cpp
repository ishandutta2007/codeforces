#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n == 1)
        cout << 0 << endl;
    else
        cout << min({a*(n-1), b*(n-1), a+c*(n-2), b+c*(n-2)}) << endl;
}