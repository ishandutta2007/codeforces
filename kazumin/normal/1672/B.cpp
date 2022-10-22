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

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int sum = 0, ok = s.back() == 'B';
        for (char c : s) {
            if (c == 'A') sum++;
            else sum--;
            if (sum < 0) ok = 0;
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}