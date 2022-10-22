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

int t, n;

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2) printf("%d\n", (n - 1) / 2);
        else printf("%d\n", n / 2);
    }

    return 0;
}