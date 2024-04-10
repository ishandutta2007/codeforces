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

        ll out = 0;
        for (int i = 0; i < 31; i++) {
            ll mask = ((ll) 1 << (ll) i);
            bool needed = true;
            for (int j = 0; j < n; j++) {
                if ((a[j] & mask) == 0) {
                    needed = false;
                    break;
                }
            }
            if (needed) {
                //cout << mask << ' ' << i << endl;
                out |= mask;
            }
        }
        cout << out << endl;
    }
}