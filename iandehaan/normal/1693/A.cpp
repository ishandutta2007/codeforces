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
        int lastnonzero = -1;
        ll sm = 0;
        rep(i, 0, n) {
            cin >> a[i];
            if (a[i] != 0) lastnonzero = i;
            sm += a[i];
        }

        if (sm != 0) {
            cout << "No\n";
            continue;
        }

        ll curramt = 0;
        bool good = true;
        rep(i, 0, n) {
            curramt += a[i];
            if (curramt < 0) {
                good = false;
                break;
            }
            if (curramt == 0) {
                if (i < lastnonzero) {
                    good = false;
                    break;
                }
            }
        }

        if (good) cout << "Yes\n";
        else cout << "No\n";




    }
}