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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        for (int i = 1; i <= n; i++) s += "9";
        int id = n - 1;
        while (n >= 4) {
            s[id] = '8';
            id--;
            n -= 4;
        }
        if (n > 0) s[id] = '8';
        printf("%s\n", s.c_str());
    }

    return 0;
}