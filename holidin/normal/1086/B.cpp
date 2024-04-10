#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
int c[N];

int main() {
    int i, j,k, n, a, b;
    long double s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        ++c[a];
        ++c[b];
    }
    k = 0;
    for (i = 1; i <= n; ++i)
    if (c[i] == 1)
        ++k;
    cout << fixed<< setprecision(18) << 2 * s / k;

}