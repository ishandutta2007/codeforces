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
        bool zero = false;
        bool one = false;
        bool two = false;
        int a[n];
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x;
            if (x == 0) zero = true;
            if (x == 1) one = true;
            if (x == 2) two = true;
        }

        if ((zero && one) || (one && two)) {
            cout << "NO" << endl;
            continue;
        }
        if (!one) {
            // reduce all to 0, starting from largest
            cout << "YES" << endl;
            continue;
        }

        // Have to reduce to one...
        sort(a, a+n);
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]+1) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}