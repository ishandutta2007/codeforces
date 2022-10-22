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

const int MN = 505;

int n;
vector<pii> ans;

void add(int x, int y) {
    ans.push_back({x, y});
}

int main() {
    boost();

    cin >> n;
    int x = 3, y = 3;
    add(1, 1);
    add(1, 2);
    add(1, 3);
    add(2, 3);
    add(3, 3);
    add(3, 2);
    add(3, 1);
    add(2, 1);
    for (int i = 1; i <= n; i++) {
        add(x, y + 1);
        add(x, y + 2);
        add(x + 1, y + 2);
        add(x + 2, y + 2);
        add(x + 2, y + 1);
        add(x + 2, y);
        add(x + 1, y);
        x += 2, y += 2;
    }
    cout << ans.size() << "\n";
    for (pii p : ans) cout << p.f << " " << p.s << "\n";

    return 0;
}