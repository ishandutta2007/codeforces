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

bool seen[200'020+1];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        rep(i, 0, n+1) seen[i] = false;

        vi out;
        rep(i, 1, n+1) {
            if (seen[i]) continue;

            seen[i] = true;
            out.pb(i);
            int curr = i*2;
            while (curr <= n) {
                seen[curr] = true;
                out.pb(curr);
                curr *= 2;
            }
        }
        cout << 2 << '\n';
        for (int x : out) cout << x << ' ';
        cout << '\n';
    }
}