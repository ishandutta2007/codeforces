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
        int n;
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        vector<pii> difs;
        rep(i, 1, n) {
            if (a[i] < a[i-1]) {
                difs.pb(mp(a[i-1]-a[i], i));
            }
        }
        sort(all(difs));
        reverse(all(difs));

        int ind = 0;
        vi out;
        for (int i = n; i >= 1; i--) {
            if (ind >= sz(difs)) out.pb(1);
            else {
                out.pb(difs[ind].second+1);
                ind++;
            }
        }
        reverse(all(out));
        for (int x : out) cout << x << ' ';
        cout << '\n';
    }
}