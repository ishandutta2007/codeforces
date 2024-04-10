#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100, inf = 1e9;
const int base = 1e9 + 7;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>

int main() {
    int n;
    cin >> n;

    n *= 2;

    set<int> cur;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (!cur.count(x)) {
            cur.insert(x);
        } else {
            cur.erase(x);
        }
        ans = max(ans, (int)cur.size());
    }
    cout << ans;
    return 0;
}