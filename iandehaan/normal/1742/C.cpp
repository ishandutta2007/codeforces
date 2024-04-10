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
    int n = 8;
    while (t--) {
        char grid[n][n];
        rep(i, 0, n) rep(j, 0, n) cin >> grid[i][j];

        char out = 'R';
        rep(j, 0, n) {
            bool good = true;
            rep(i, 0, n) if (grid[i][j] != 'B') good = false;
            if (good) out = 'B';
        }
        cout << out << endl;
    }
}