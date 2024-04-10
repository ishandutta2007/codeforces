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

int32_t main() {
    boost();

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        int zr = 0, on = 0, pair = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (zr > 0) zr--, pair++;
                else on++;
            } else {
                if (on > 0) on--, pair++;
                else zr++;
            }
        }
        if (pair % 2) printf("DA\n");
        else printf("NET\n");
    }

    return 0;
}