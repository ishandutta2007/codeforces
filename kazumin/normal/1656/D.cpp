#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int n;

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int pw = 1;
        int N = n;
        while (n % 2 == 0) pw *= 2, n /= 2;
        pw *= 2;
        if (pw + 1 <= N * 2 / pw) printf("%lld\n", pw);
        else {
            assert(n + 1 <= N * 2 / n);
            if (n != 1 && n + 1 <= N * 2 / n) printf("%lld\n", n);
            else printf("-1\n");
        }

    }

    return 0;
}