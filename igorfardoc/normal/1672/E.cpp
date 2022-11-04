#include<bits/stdc++.h>
#define prev prev1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

int q(int w) {
	cout << "? " << w << endl;
	int res;
	cin >> res;
	return res;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int now = 4004000;
	for(int i = 22; i >= 0; i--) {
		int here = now - (1 << i);
		if(here < 1) continue;
		if(q(here) == 1) now = here;
	}
	int ans = now;
	int sum = now - n + 1;
	bool nxt = true;
	for(int i = 2; i <= n; i++) {
		int needspaces = (ans - sum) - 1;
		int here = (needspaces + sum) / i;
		if(here == 0) {
			break;
		}
		int res = q(here);
		if(res == 0) {
			break;
		}
		if(res <= i) {
			ans = min(ans, res * here);
		}
	}
	cout << "! " << ans << endl;

}