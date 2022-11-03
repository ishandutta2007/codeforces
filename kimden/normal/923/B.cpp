#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100005], b[100005];
ll v, t;
ll cur = 0;
multiset<ll> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i) {
        v = a[i];
        t = b[i];
        s.insert(cur + v);
        ll ans = 0;
        while (s.size() && *s.begin() <= cur + t) {
            ans += *s.begin() - cur;
            s.erase(s.begin());
        }
        ans += s.size() * ll(t);
        cout << ans << " ";
        cur += t;
    }
    cout << endl;
}