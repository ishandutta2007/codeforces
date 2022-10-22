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

int t, n, a[MN], freq[MN], ans[MN];
pii b[MN];
vector<int> pos[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], freq[a[i]]++, pos[a[i]].push_back(i);
        for (int i = 1; i <= n; i++) b[i - 1] = {freq[i], i};
        sort(b, b + n, greater<>());
        for (int i = 0; i < n; i++) {
            int links = b[i].f;
            int j = (i + 1) % n;
            while (links) {
                while (links && pos[b[j].s].size()) {
                    links--;
                    ans[pos[b[j].s].back()] = b[i].s;
                    pos[b[j].s].pop_back();
                }
                j = (j + 1) % n;
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%lld ", ans[i]);
            freq[i] = 0;
            pos[i].clear();
        }
        printf("\n");
    }

    return 0;
}