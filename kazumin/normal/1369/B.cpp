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

int main() {
    boost();

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int f = 0x3f3f3f3f, se = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {f = i; break;}

        }
        for (int i = 0; i < n; i++) if (s[i] == '0') se = i;
        int pr = 0;
        //printf("%d %d\n", f, se);
        for (int i = 0; i < n; i++) {
            if (f <= i && i <= se) {
                if (!pr) printf("0"), pr = 1;
            } else printf("%c", s[i]);
        }
        printf("\n");
    }

    return 0;
}