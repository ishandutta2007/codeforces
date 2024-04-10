// Retired?
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10005];
pair<int, int> z[105];

int main() {
    ios::sync_with_stdio(!cin.tie(0));
    cin >> n >> k;
    for (int i=1; i<=n*k; i++) cin >> a[i];
    for (int l=1; l<=n; l+=k-1) {
        int r = l + k - 2;
        r = min(r, n);
        map<int, int> mp;
        set<int> good;
        for (int x=l; x<=r; x++) good.insert(x);
        for (int i=1; i<=n*k; i++) {
            if (good.count(a[i])) {
                if (mp.count(a[i])) {
                    z[a[i]] = {mp[a[i]], i};
                    good.erase(a[i]);
                    mp.clear();
                } else {
                    mp[a[i]] = i;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) cout << z[i].first << ' ' << z[i].second << '\n';
}