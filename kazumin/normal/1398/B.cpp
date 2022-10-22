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

int n, a[500005];

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int on = 0, len = 0;
        vector<int> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') len++;
            else {
                if (len > 0) v.push_back(len);
                len = 0;
            }
        }
        if (len > 0) v.push_back(len);
        sort(v.begin(), v.end(), greater<>());
        int ans = 0;
        for (int i = 0; i < v.size(); i += 2) ans += v[i];
        printf("%d\n", ans);
    }

    return 0;
}