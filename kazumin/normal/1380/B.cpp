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

int t, c[3];


int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        string s, ans;
        c[0] = c[1] = c[2] = 0;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') c[0]++;
            else if (s[i] == 'P') c[1]++;
            else c[2]++;
        }
        if (c[0] >= c[1] && c[0] >= c[2]) for (int i = 0; i < s.size(); i++) ans += 'P';
        else if (c[1] >= c[0] && c[1] >= c[2]) for (int i = 0; i < s.size(); i++) ans += 'S';
        else for (int i = 0; i < s.size(); i++) ans += 'R';
        printf("%s\n", ans.c_str());
    }

    return 0;
}