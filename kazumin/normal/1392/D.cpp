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

const int MN = 200005;

int n, a[MN], out[MN], bad[MN];
char c;
vector<int> in[MN];

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> c;
            if (c == 'R') {
                a[i] = 1;
                out[i] = i + 1;
                if (out[i] > n) out[i] -= n;
                in[out[i]].push_back(i);
            } else {
                out[i] = i - 1;
                if (out[i] < 1) out[i] += n;
                in[out[i]].push_back(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (in[i].size() == 1 && out[i] != in[i][0]) bad[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (bad[i] == 0) {
                int pre = i - 1;
                int nxt = i + 1;
                if (pre < 1) pre += n;
                if (nxt > n) nxt -= n;
                assert(bad[pre] == 0 || bad[nxt] == 0);
            }
        }
        vector<int> v;
        int l = 1, r = n;
        while (l <= n && bad[l] == 1) l++;
        while (r >= 1 && bad[r] == 1) r--;
        if (l > r) {
            printf("%d\n", (n + 2) / 3);
        } else {
            v.push_back(n - r + l - 1);
            int len = 0;
            for (int i = l; i <= r; i++) {
                if (bad[i]) len++;
                else {
                    v.push_back(len);
                    len = 0;
                }
            }
            v.push_back(len);
            int ans = 0;
            for (int p : v) ans += (p + 2) / 3;
            printf("%d\n", ans);
        }
        for (int i = 1; i <= n; i++) {
            in[i].clear();
            out[i] = 0;
            a[i] = 0;
            bad[i] = 0;
        }

    }

    return 0;
}