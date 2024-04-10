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
        ll numeven = 0;
        ll numodd = 0;
        ll sumeven = 0;
        ll sumodd = 0;
        rep(i, 0, n) {
            ll x;
            cin >> x;
            if (x % 2 == 0) {
                numeven++;
                sumeven += x;
            } else {
                numodd++;
                sumodd += x;
            }
        }

        while (q--) {
            int cmd;
            cin >> cmd;
            ll x;
            cin >> x;
            if (cmd == 0) {
                // add to even
                if (x % 2 == 0) {
                    // even + even = even
                    sumeven += x*numeven;
                } else {
                    // even + odd = odd
                    sumeven += x*numeven;
                    sumodd += sumeven;
                    numodd += numeven;
                    numeven = 0;
                    sumeven = 0;
                }
            } else {
                // add to odd
                if (x % 2 == 0) {
                    // odd + even = odd
                    sumodd += x*numodd;
                } else {
                    // odd + odd = even;
                    sumodd += x*numodd;
                    sumeven += sumodd;
                    numeven += numodd;
                    numodd = 0;
                    sumodd = 0;
                }
            }

            cout << sumeven + sumodd << '\n';
        }
    }
}