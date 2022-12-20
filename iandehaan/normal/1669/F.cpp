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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        map<ll, int> reachable;
        reachable[0] = n;
        ll rtsm = 0;
        for (int i = n-1; i >= 0; i--) {
            rtsm += a[i];
            reachable[rtsm] = i;
        }

        int out = 0;
        ll sm = 0;
        for (int i = 0; i < n ; i++) {
            sm += a[i];
            if (reachable.count(sm) == 0) continue;
            int reachind = reachable[sm];
            if (reachind <= i) continue;
            out = max(out, i+1 + (n-reachind));
        }
        cout << out << endl;
    }
}