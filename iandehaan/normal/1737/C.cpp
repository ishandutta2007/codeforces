#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef pair<pii, pair<pii, pii>> state;

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
        pii r[3];
        rep(i, 0, 3) {
            cin >> r[i].first >> r[i].second;
        }
        set<pii> coords;
        rep(i, 0, 3) coords.insert(r[i]);

        int specind = -1;
        bool lcase = false;
        rep(i, 0, 3) {
            if (r[i] == mp(1, 1) || r[i] == mp(n, n) || r[i] == mp(1, n) || r[i] == mp(n, 1)) {
                specind = i;
                break;
            }
        }

        if (coords.count(mp(1, 1)) + coords.count(mp(2, 1)) + coords.count(mp(1, 2)) == 3) lcase = true;
        if (coords.count(mp(n, n)) + coords.count(mp(n-1, n)) + coords.count(mp(n, n-1)) == 3) lcase = true;
        if (coords.count(mp(n, 1)) + coords.count(mp(n-1, 1)) + coords.count(mp(n, 2)) == 3) lcase = true;
        if (coords.count(mp(1, n)) + coords.count(mp(2, n)) + coords.count(mp(1, n-1)) == 3) lcase = true;

        //cout << lcase << endl;

        int x, y;
        cin >> x >> y;

        if (!lcase) {
            int singlerow = r[0].first^r[1].first^r[2].first;
            int parity = 0;
            int rowparity = singlerow%2;
            rep(i, 0, 3) {
                if (r[i].first == singlerow) {
                    parity = (r[i].first+r[i].second)%2;
                }
            }

            if (rowparity != (x%2)) {
                cout << "YES" << endl;
            } else {
                if (parity == ((x+y)%2)) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        } else {
            if (x == r[specind].first || y == r[specind].second) {
                // just walk to it
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }




    }
}