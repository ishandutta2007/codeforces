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
        int a[n];
        rep(i, 0, n) cin >> a[i];

        int out = n;

        for (int j = 0; j < n; j++) {
            ll target = 0;
            for (int i = 0; i <= j; i++) target += a[i];

            int thickness = j+1;
            int currlen = 0;
            ll currsm = 0;
            for (int i = j+1; i < n; i++) {
                currsm += a[i];
                currlen++;
                if (currsm == target) {
                    thickness = max(thickness, currlen);
                    currsm = 0;
                    currlen = 0;
                }
            }
            if (currsm == 0) out = min(out, thickness);
        }
        cout << out << endl;
    }
}