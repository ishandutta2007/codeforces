#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    ll ans = 0;
    int cur = a.back();
    for (int i = int(a.size()) - 1; i >= 0; --i) {
        int take = min(a[i], cur);
        ans += take;
        cur = max(0, take - 1);
    }
    cout << ans << endl;

    return 0;
}