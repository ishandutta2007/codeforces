#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 1 << 21;
int cnt[2][N];

int main() {
    int n;
    scanf("%d", &n);
    ll ans = 0;
    int prefix = 0;
    cnt[1][0] = 1;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        prefix ^= x;
        ans += cnt[i & 1][prefix];
        cnt[i & 1][prefix] += 1;
    }
    cout << ans << endl;

    return 0;
}