#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, a, b, n, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> n >> m;
        if (min(a, b) >= m && a + b - m >= n) cout << "Yes\n"; else cout << "No\n";
    }
    return 0;
}