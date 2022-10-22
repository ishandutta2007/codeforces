#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

ll cnt[12];
string s;

int32_t main() {
    boost();

    s = "fcodeforces";
    ll t;
    cin >> t;
    for (int i = 1; i <= 10; i++) cnt[i] = 1;
    int prod = 1;
    while (prod < t) {
        for (int i = 1; i <= 10; i++) {
            prod /= cnt[i];
            cnt[i]++;
            prod *= cnt[i];
            if (prod >= t) break;
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= cnt[i]; j++) printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}