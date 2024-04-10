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
        int n, m;
        cin >> n >> m;
        string grid[n];
        rep(i, 0, n) cin >> grid[i];

        int minplus = 1e9;
        int maxplus = -1e9;
        int minsub = 1e9;
        int maxsub = -1e9;
        rep(i, 0, n) rep(j, 0, m) if (grid[i][j] == 'B') {
            minplus = min(minplus, i+j);
            maxplus = max(maxplus, i+j);
            minsub = min(minsub, i-j);
            maxsub = max(maxsub, i-j);
        }

        int bestdist = 1e9;
        pii out = mp(0, 0);
        rep(i, 0, n) rep(j, 0, m) {
            //cout << "at " << i << ' ' << j << endl;
            int med = max(
                max((i+j)-minplus, maxplus-(i+j)),
                max((i-j)-minsub, maxsub-(i-j))
            );
            if (med < bestdist) {
                bestdist = med;
                out = mp(i, j);
            }
        }
        cout << out.first+1 << ' ' << out.second+1 << '\n';
    }
}