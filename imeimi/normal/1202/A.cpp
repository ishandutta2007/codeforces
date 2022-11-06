#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char x[100001], y[100001];
void solve() {
    cin >> x >> y;
    int n = strlen(x), m = strlen(y);
    int ly, k;
    for (ly = m - 1; y[ly] == '0'; --ly);
    for (k = 0; x[n - (m - ly) - k] == '0'; ++k);
    printf("%d\n", k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}