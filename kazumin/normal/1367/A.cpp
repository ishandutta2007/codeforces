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

int t;
string s;

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> s;
        string ans = "";
        ans += s[0];
        for (int i = 1; i < s.size(); i += 2) ans += s[i];
        printf("%s\n", ans.c_str());
    }

    return 0;
}