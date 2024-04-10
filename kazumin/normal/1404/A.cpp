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

const int MN = 300005;

int n, k, p1[MN], p0[MN];
string s;

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        bool ok = 1;
        for (int i = k; i < n; i++) {
            if ((s[i - k] == '1' && s[i] == '0') || (s[i - k] == '0' && s[i] == '1')) ok = 0;
            if (s[i - k] == '?' && s[i] != '?') s[i - k] = s[i];
            if (s[i - k] != '?' && s[i] == '?') s[i] = s[i - k];
        }
        if (!ok) { printf("NO\n"); continue; }
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') p1[i]++;
            if (s[i - 1] == '0') p0[i]++;
            p1[i] += p1[i - 1];
            p0[i] += p0[i - 1];
        }
        for (int i = k; i <= n; i++) {
            if (p1[i] - p1[i - k] > k / 2) ok = 0;
            if (p0[i] - p0[i - k] > k / 2) ok = 0;
        }
        //printf("%s\n", s.c_str());
        if (!ok) printf("NO\n");
        else printf("YES\n");
        for (int i = 1; i <= n; i++) p1[i] = p0[i] = 0;
    }

    return 0;
}