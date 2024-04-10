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

const int MN = 2005;

int n, a[MN], rev[MN], t;

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], rev[a[i]] = i;
        bool can = 0;
        int l = 1, r = n;
        for (int i = n; i >= 1; i--) {
            if (rev[i] == l) l++;
            else if (rev[i] == r) r--;
            else {
                can = 1;
                printf("YES\n%d %d %d\n", rev[i] - 1, rev[i], rev[i] + 1);
                break;
            }
        }
        if (!can) printf("NO\n");
    }

    return 0;
}