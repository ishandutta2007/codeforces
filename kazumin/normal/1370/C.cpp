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

int t, n;

bool prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        int N = n;
        int cnt = 0;
        while (n % 2 == 0) n /= 2, cnt++;


        if ((n == 1 && cnt > 1) || (N == 1) || (prime(n) && cnt == 1)) printf("FastestFinger\n");
        else printf("Ashishgup\n");
    }

    return 0;
}