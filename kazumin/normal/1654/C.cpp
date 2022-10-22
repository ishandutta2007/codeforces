#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int t, n, a[MN], cnt;
map<int, int> mp;

void rec(int x) {
    if (cnt > n) return;
    if (mp.count(x) && mp[x] > 0) {mp[x]--; return;}
    cnt++;
    if (cnt > n) return;
    rec(x / 2);
    rec((x + 1) / 2);
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++, sum += a[i];
        cnt = 1;
        rec(sum);
        if (cnt == n) printf("YES\n");
        else printf("NO\n");
        mp.clear();
    }

    return 0;
}