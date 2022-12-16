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
        vi pos[n];
        rep(i, 0, n) {
            int x;
            cin >> x;
            x--;
            pos[x].pb(i);
        }
        rep(i, 0, n) {
            if (sz(pos[i]) == 0) {
                cout << 0 << ' ';
                continue;
            }
            int curr = 1;
            int prev = pos[i][0];
            rep(j, 1, sz(pos[i])) {
                if ((pos[i][j]-prev-1)%2 == 0) {
                    curr++;
                    prev = pos[i][j];
                } 
            }
            cout << curr << ' ';
        }
        cout << '\n';
    }    
}