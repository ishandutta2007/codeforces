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

        int mxor = 0;
        rep(i, 0, n) mxor |= a[i];

        set<int> taken;
        vi out;
        int curror = 0;
        while (curror != mxor) {
            int mxind = -1;
            rep(i, 0, n) {
                if (taken.count(i)) continue;
                if (mxind == -1 || (a[i] & (~curror)) > (a[mxind] & (~curror))) mxind = i;
            }

            curror |= a[mxind];
            taken.insert(mxind);
            out.pb(a[mxind]);
        }

        rep(i, 0, n) if (taken.count(i) == 0) out.pb(a[i]);
        rep(i, 0, n) cout << out[i] << ' ';
        cout << '\n';
    }
}