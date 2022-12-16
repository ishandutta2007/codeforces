#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 200'010

int n;
vector<int> children[MAXN];
pair<ll, ll> a[MAXN];


// (cost, max route amount)
pair<int, ll> dfs(int curr) {
    int med = sz(children[curr]) - 1;
    ll maxroute = 0;
    for (int nxt : children[curr]) {
        pair<int, ll> rec = dfs(nxt);
        maxroute += rec.second;
        med += rec.first;
    }
    maxroute = min(maxroute, a[curr].second);

    if (maxroute < a[curr].first) {
        maxroute = a[curr].second;
        med++;
    }

    return mp(med, maxroute);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        rep(i, 0, n) children[i].clear();
        rep(i, 1, n) {
            int par;
            cin >> par;
            par--;
            children[par].pb(i);
        }

        rep(i, 0, n) cin >> a[i].first >> a[i].second;

        cout << dfs(0).first+1 << '\n';
    }
}