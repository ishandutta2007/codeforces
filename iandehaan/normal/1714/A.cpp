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
        int n, h, m;
        cin >> n >> h >> m;
        int starttime = h*60 + m;
        int out = 24*60;
        rep(i, 0, n) {
            int x, y;
            cin >> x >> y;
            int thistime = x*60 + y;
            int diff = thistime-starttime;
            if (diff < 0) diff += 60*24;
            out = min(out, diff);
        }
        cout << out/60 << ' ' << out%60 << '\n';
    }
}