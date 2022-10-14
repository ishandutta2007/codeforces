#include<bits/extc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
using ll = long long;
const int maxn = 250, mod =998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int l, r;cin >> l >> r;
		cout << (r < 2*l ? "YES\n" : "NO\n");
	}
	return 0;
}