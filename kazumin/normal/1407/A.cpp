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

const int MN = 1005;

int n, a[MN];

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int c1 = 0, c0 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i]) c1++;
            else c0++;
        }
        if (c0 < c1) {
            int rem = n - c0;
            if (rem % 2) rem--;
            printf("%d\n", rem);
            for (int i = 1; i <= rem; i++) printf("1 ");
            printf("\n");
        } else {
            int rem = n - c1;
            printf("%d\n", rem);
            for (int i = 1; i <= rem; i++) printf("0 ");
            printf("\n");
        }
    }

    return 0;
}