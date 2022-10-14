#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < n; j++) {
			cout << ((j&1)<<(i+j)) << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while(q--) {
		ll k; cin >> k;
		int x = 1, y = 1;
		cout << "1 1\n";
		while(x != n || y != n) {
			if((k&1) == ((k/2)&1)) x++;
			else y++;
			cout << x << " " << y << '\n';
			k>>=1;
		}
		cout.flush();
	}
}