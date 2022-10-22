#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 45;

int t, n, a[MN];

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        int bo = 0, be = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2 == 1 && a[i] % 2 == 0) bo++;
            if (i % 2 == 0 && a[i] % 2 == 1) be++;
        }
        if (be != bo) printf("-1\n");
        else printf("%d\n", bo);
    }

    return 0;
}