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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int m;
    cin >> m;
    ll x[m];
    ll y[m];
    for (int i = 0; i < m; i++) cin >> x[i] >> y[i];

    ll sm = 0;
    for (int i = 0; i < n; i++) sm += a[i];

    for (int i = 0; i < m; i++) {
        // search for smallest i such that a[i] >= x[i]
        auto iter = lower_bound(all(a), x[i]);
        if (iter == begin(a)) {
            ll mysm = sm - a[0];
            cout << max((ll)0, y[i]-mysm) << endl;
        } else if (iter == end(a)) {
            //cout << "this case" << endl;
            iter--;
            cout << max((ll) 0, x[i] - *iter + max((ll) 0, y[i] - (sm-*iter))) << endl;
        } else {
            ll bestout = y[i] - (sm-*iter);
            //cout << bestout << endl;
            iter--;
            bestout = min(bestout, x[i]-*iter + max((ll) 0, y[i] - (sm-*iter)));
            cout << max((ll)0, bestout) << endl;
        }
    }
}