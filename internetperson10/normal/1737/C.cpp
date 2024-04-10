#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[4], b[4];
    for(int i = 0; i < 4; i++) {
        cin >> a[i] >> b[i];
    }
    bool ok = false;
    for(int i = 0; i < 3; i++) {
        if(a[i] % 2 == a[3] % 2 && b[i] % 2 == b[3] % 2) {
            ok = true;
        }
    }
    int lx = ((a[0] + a[1] + a[2]) - (a[0] ^ a[1] ^ a[2])) >> 1;
    int rx = ((b[0] + b[1] + b[2]) - (b[0] ^ b[1] ^ b[2])) >> 1;
    if((lx % (n-1) == 1) && (rx % (n-1) == 1)) {
        ok = false;
        if((lx == a[3]) || (rx == b[3])) {
            ok = true;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}