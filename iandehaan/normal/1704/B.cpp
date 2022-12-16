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

int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int out = 0;
        int n, x;
        cin >> n >> x;
        rep(i, 0, n) cin >> a[i];

        int mn = a[0];
        int mx = a[0];
        rep(i, 0, n) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);

            if (mx-mn > 2*x) {
                // reset
                out++;
                mn = a[i];
                mx = a[i];
            }
        }
        cout << out << '\n';
    }
}