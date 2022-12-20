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
ll a[MAXN];
ll sm[MAXN];
ll mx[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        rep(i, 0, n) cin >> a[i];
        sm[0] = a[0];
        mx[0] = a[0];
        rep(i, 1, n) {
            mx[i] = max(mx[i-1], a[i]);
            sm[i] = sm[i-1] + a[i];
        }

        while (q--) {
            ll k;
            cin >> k;

            int lo = -1;
            int hi = n;
            while (hi-lo > 1) {
                int mid = (hi+lo)/2;

                if (mx[mid] > k) hi = mid;
                else lo = mid;
            }

            if (lo >= 0) cout << sm[lo] << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
}