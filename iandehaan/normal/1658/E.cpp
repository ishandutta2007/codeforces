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

    int n, k;
    cin >> n >> k;

    int a[n][n];
    vector<pair<int, pair<int, int>>> b;
    for (int i = 0; i < n; i++) for (int j = 0 ; j < n; j++) {
        cin >> a[i][j];
        b.pb(mp(a[i][j], mp(i, j)));
    }

    sort(all(b));
    reverse(all(b));
    pair<int, int> p1 = b[0].second;
    pii p2 = b[0].second;
    pii p3 = b[0].second;
    pii p4 = b[0].second;
    char out[n][n];
    out[b[0].second.first][b[0].second.second] = 'M';
    for (int i = 1; i < sz(b); i++) {
        int x = b[i].second.first;
        int y = b[i].second.second;
        int mxdist = abs(x -p1.first) + abs(y - p1.second);
        mxdist = max(mxdist, abs(x -p2.first) + abs(y - p2.second));
        mxdist = max(mxdist, abs(x -p3.first) + abs(y - p3.second));
        mxdist = max(mxdist, abs(x -p4.first) + abs(y - p4.second));
        if (mxdist <= k) {
            out[x][y] = 'M';

            int p1val = -1 * (x + y);
            int p2val = (-1*x) + y;
            int p3val = x + y;
            int p4val = x + (-1*y);

            if (p1val > (-1*(p1.first+p1.second))) {
                p1 = mp(x, y);
            }

            if (p2val > ((-1*p2.first) + p2.second)) {
                p2 = mp(x, y);
            }

            if (p3val > (p3.first + p3.second)) {
                p3 = mp(x, y);
            }

            if (p4val > (p4.first + (-1*p4.second))) {
                p4 = mp(x, y);
            }
        } else {
            out[x][y] = 'G';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << out[i][j];
        cout << endl;
    }



}