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

const int MN = 100005;

int a[MN], on[MN], zr[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int x, n;
        string s;
        cin >> s >> x;
        n = s.size();
        for (int i = 1; i <= n; i++) {
            a[i] = s[i - 1] - '0';
            if (!a[i]) {
                if (i + x <= n) zr[i + x] = 1;
                if (i - x > 0) zr[i - x] = 1;
            }
        }
        bool meme = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                bool ok = 0;
                if (i + x <= n) ok |= !zr[i + x];
                if (i - x > 0) ok |= !zr[i - x];
                meme = ok & meme;
            }
        }
        if (!meme) printf("-1\n");
        else {
            for (int i = 1; i <= n; i++) {
                if (zr[i]) printf("0");
                else printf("1");
            }
            printf("\n");
        }
        for (int i = 1; i <= n; i++) zr[i] = 0;
    }

    return 0;
}