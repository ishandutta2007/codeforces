#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    int diff = abs(a - b);
    cout << (diff / 2 * (diff / 2 + 1)) + (diff % 2 ? diff / 2 + 1 : 0) << endl;
}