#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint x, s;
llint sol[5];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> s;
    if (s - x < 0 || (s - x) % 2 != 0) {
        cout << -1;
        return 0;
    }
    s = (s - x) / 2;
    int mx = 0;
    for (int i = 0; i < 62; i++) {
        int val = !!(x & (1LL << i)) + 2 * (!!(s & (1LL << i)));
        mx = max(mx, val);
        for (int j = 0; j < val; j++) {
            sol[j] |= (1LL << i);
        }
    }
    cout << mx << endl;
    for (int i = 0; i < mx; i++) cout << sol[i] << " ";
    return 0;
}