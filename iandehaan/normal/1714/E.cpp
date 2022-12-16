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
        map<ll, int> cnts;
        string out = "NO";
        ll a[n];
        rep(i, 0, n) cin >> a[i];
        for (int ending = 0; ending < 9; ending++) {
            //cout << ending << endl;
            bool all = true;
            rep(i, 0, n-1) {
                if (a[i] != a[i+1]) all = false;
            }
            if (all) {
                out = "YES";
                break;
            }

            if (ending == 5 || ending == 1 || ending == 7 || ending == 9 || ending == 3) {
                continue; // not reachable
            }

            if (ending == 0) {
                // everything must be 5 or 0
                bool ok = true;
                rep(i, 0, n) {
                    if (a[i] % 10 != 0 && a[i] % 10 != 5) {
                        ok = false;
                    }
                }

                if (!ok) continue;

                ll b[n];
                rep(i, 0, n) b[i] = a[i];

                rep(i, 0, n) {
                    if (b[i] % 10 == 5) b[i] += 5;
                }

                rep(i, 0, n-1) {
                    if (b[i] != b[i+1]) ok = false;
                }

                if (ok) {
                    out = "YES";
                    break;
                }
            } else {
                // nothing can be 5 or 0
                bool ok = true;
                rep(i, 0, n) {
                    if (a[i] % 10 == 0 || a[i] % 10 == 5) {
                        ok = false;
                    }
                }
                if (!ok) continue;

                ll b[n];
                rep(i, 0, n) b[i] = a[i];

                rep(i, 0, n) {
                    while (b[i] % 10 != ending) {
                        b[i] += b[i] % 10;
                    }
                }

                rep(i, 0, n-1) {
                    if (abs(b[i]-b[i+1]) % 20 != 0) ok = false;
                }

                if (ok) {
                    out = "YES";
                    break;
                }
            }
        }

        cout << out << '\n';
    }
}