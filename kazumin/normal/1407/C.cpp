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

const int MN = 10005;

int n, ans[MN];

int guess(int i, int j) { //returns ans[i] % ans[j]
    cout << "? " << i << " " << j << "\n" << flush;
    int tmp;
    cin >> tmp;
    if (tmp == -1) abort();
    return tmp;
}

int main() {
    boost();

    cin >> n;
    int l = 1;
    for (int i = 2; i <= n; i++) {
        int p1 = guess(l, i);
        int p2 = guess(i, l);
        if (p2 > p1) {
            ans[i] = p2;
        } else {
            ans[l] = p1;
            l = i;
        }
    }
    ans[l] = n;
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n" << flush;

    return 0;
}