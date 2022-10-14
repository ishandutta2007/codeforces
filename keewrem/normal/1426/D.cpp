#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define nl '\n'
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = 0x3f3f3f3f;
const ll MAXN = 3e5;
ll pre, n, j, a, last = INF;
priority_queue<ii,vector<ii>,greater<ii>> q;
map<ll,ll> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    m[0]=1;
    for (ll i = 1; i <= n; i++) {
        cin >> a;
        pre += a;
        if (m[pre]) q.push({m[pre], i});
        m[pre] = i+1;
    }
    while (q.size()) {
        while (q.size() && q.top().ff < last) {
            last = min(q.top().ss, last);
            q.pop();
        }
        last = INF;
        j++;
    }
    cout << j << nl;
}