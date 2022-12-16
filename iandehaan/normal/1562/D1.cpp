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
        int n, q;
        cin >> n >> q;
        int vals[n];
        int pref[n];
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == '+') {
                if (i % 2 == 0) vals[i] = 1;
                else vals[i] = -1;
            } else {
                if (i % 2 == 0) vals[i] = -1;
                else vals[i] = 1;
            }


            if (i == 0) pref[i] = vals[i];
            else pref[i] = pref[i-1] + vals[i];

            //cout << i << ' ' << vals[i] << endl;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int out = pref[r];
            if (l != 0) out -= pref[l-1];
            //cout << out << endl;
            if (out == 0) {
                cout << 0 << endl;
            } else if (out % 2 == 0) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        }
    }
}