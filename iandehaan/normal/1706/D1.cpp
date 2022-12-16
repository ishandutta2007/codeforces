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
        int n, k;
        cin >> n >> k;
        int a[n];
        rep(i, 0, n) cin >> a[i];

        int out = 3000;

        for (int mx = 0; mx <= 3000; mx++) {
            bool poss = true;
            int mn = mx;
            rep(i, 0, n) {
                if (a[i] / k > mx) {
                    poss = false;
                    break;
                }
                int needed = a[i]+1;
                if (mx != 0) needed = a[i] / mx;
                if (needed == 0) needed++;
                while (a[i] / needed > mx) needed++;
                mn = min(mn, a[i] / needed);
            }
            if (!poss) continue;

            out = min(out, mx-mn);
        }
        cout << out << '\n';
    }
}