#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    set<int> sq;
    for (int i = 1; i <= 100000; i++) sq.insert(i * i);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0 && sq.count(n / 2)) printf("YES\n");
        else if (n % 4 == 0 && sq.count(n / 4)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}