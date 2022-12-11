#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int inf = 1e9;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int W, H;
    	int x1, y1, x2, y2;
    	int w, h;
    	cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    	int ans = inf;
    	if (!(x1 <= w && y1 <= h)) {
    		ans = 0;
    	}
    	if (!(x1 <= w && y2 >= H - h)) {
    		ans = 0;
    	}
    	if (!(x2 >= W - w && y1 <= h)) {
    		ans = 0;
    	}
    	if (!(x2 >= W - w && y2 >= H - h)) {
    		ans = 0;
    	}
    	int a = abs(x2 - x1);
    	int b = abs(y2 - y1);
    	if (w + a <= W) {
    		ans = min(ans, abs(x1 - w));
    		ans = min(ans, abs(x1 - (W - w - a)));
    	}
    	if (h + b <= H) {
    		ans = min(ans, abs(y1 - h));
    		ans = min(ans, abs(y1 - (H - h - b)));
    	}
    	if (ans == inf) {
    		ans = -1;
    	}
    	cout << ans << "\n";
    }

}