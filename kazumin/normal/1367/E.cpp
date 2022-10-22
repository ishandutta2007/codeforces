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

int n, k, cnt[30], nxt[MN], vis[MN], tmp[30];
string s;

int main() {
    boost();

    int t; cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> k >> s;
        for (char c : s)  cnt[c - 'a']++;
        /*for (char c : v) printf("%c ", c);
        printf("\n");
        for (int i = 0; i < 26; i++) printf("%d ", cnt[i]);
        printf("\n");*/
        for (int len = n; len > 0; len--) {
            for (int i = 0; i < 26; i++) tmp[i] = cnt[i];
            for (int i = 1; i <= len; i++) {
                nxt[i] = (i + k) % len;
                if (nxt[i] == 0) nxt[i] += len;
                vis[i] = 0;
            }
            bool can = 1;
            for (int i = 1; i <= len; i++) {
                if (vis[i]) continue;
                int len = 1;
                int j = i;
                vis[j] = 1;
                while (!vis[nxt[j]]) j = nxt[j], vis[j] = 1, len++;
                int f = 0;
                for (int i = 0; i < 26; i++) {
                    if (tmp[i] >= len) {
                        tmp[i] -= len;
                        f = 1;
                        break;
                    }
                }
                if (!f) can = 0;
            }
            if (can) {
                printf("%d\n", len);
                break;
            }
        }
    }

    return 0;
}