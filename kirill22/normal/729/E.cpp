#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    s--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = n - 1, dopping = 0;
    if (a[s] != 0) a[s] = 0, dopping++;
    multiset<int> b;
    for (int i = 0; i < n; i++) if (i != s && a[i]) b.insert(a[i]);
    int L = 1, c = 1;
    for (int k = 1; k < n; k++) {
        if (b.find(k) != b.end()) {
            L++;
            c++;
            b.erase(b.find(k));
        }
        while (b.size() > 0 && *b.begin() <= k) c++, b.erase(b.begin());
        int z = n - c;
        int need = (k + 1) - L;
        if (z >= need) ans = min(ans, z);
        else ans = min(ans, need);
    }
    cout << ans + dopping;
}