#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, k, a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        set<int> s;
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (s.count(k + a[i]) || s.count(a[i] - k)) ok = 1;
            s.insert(a[i]);
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}