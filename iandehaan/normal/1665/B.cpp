#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back 
#define mp make_pair

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        int out = 0;
        sort(a, a+n);
        int mxnum = 1;
        int currun = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) {
                currun++;
                mxnum = max(mxnum, currun);

            } else {
                currun = 1;
            }
        }

        int currhave = mxnum;
        while (currhave < n) {
            int diff = n-currhave;
            if (diff >= currhave) {
                out += currhave+1; // dupe, copy all
                currhave *= 2;
            } else {
                out += diff+1;
                currhave = n;
            }
        }

        cout << out << endl;
    }
}