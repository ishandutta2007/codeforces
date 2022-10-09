// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

constexpr int H = 1000000;

int n;
char a[1000005];
int b[1000005];
int meb[1000005], sol;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    meb[1] = 1;

    for (int i=1; i<=H; i++) {
        for (int j=2*i; j<=H; j+=i) {
            meb[j] -= meb[i];
        }
    }

    cin >> n;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    for (int i=H; i>=1; i--) {
        if (a[i]) continue;
        int k=0;
        for (int j=i; j<=H; j+=i) {
            b[++k] = a[j];
        }
        for (int j=1; j<=k; j++) {
            for (int l=2*j; l<=k; l+=j) {
                b[j] += b[l];
            }
        }

        // save some loops
        ll z = 0;
        for (int j=1; j<=k; j++) {
            z += 1ll * meb[j] * b[j] * b[j];
        }

        if (z != 0) {
            a[i] = 1;
            sol++;
        }
    }
    
    cout << sol << '\n';
}