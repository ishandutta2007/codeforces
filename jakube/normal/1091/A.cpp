#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int y, b, r;
    cin >> y >> b >> r;
    int x = min({y, b-1, r-2});
    cout << x * 3 + 3 << '\n';
}