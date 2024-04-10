#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, a, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (b <= 2*a) cout << (a + b) / 3 << '\n'; else cout << a << '\n';
    }
    return 0;
}