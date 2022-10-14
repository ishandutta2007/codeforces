#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1e3 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
array<int, 3> ans[maxn];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 0; i < maxn; i++) ans[i] = {-1, -1, -1};
    for(int i = 0; i < maxn; i+=3)
		for(int j = 0; i+j < maxn; j+=5)
			for(int k = 0; i+j+k < maxn; k+=7)
				ans[i+j+k] = {i/3, j/5, k/7};
	int t;
	cin >> t;
	for(int k; t--;) {cin >> k;if(ans[k][0] == -1) cout << "-1\n"; else cout << ans[k][0] << " " << ans[k][1] << " " << ans[k][2] << '\n';}
}