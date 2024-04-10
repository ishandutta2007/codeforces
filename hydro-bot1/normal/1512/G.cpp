// Hydro submission #61aad7cf3db3dedd6b6f55a6@1638586319574
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = (int)1e7 + 5;
void solve() {
	vector<int>res(MAXN, 0);
	vector<int>ans(MAXN, 0x3f3f3f3f);
	for (int i = 1; i < MAXN; ++i) {
		for (int j = i; j < MAXN; j += i) {
			res[j] += i;
		}
	}
 
	for (int i = 1; i < MAXN; ++i) {
		if(res[i] < MAXN)
			ans[res[i]] = min(ans[res[i]], i);
	}
	int t, c;
	cin >> t;
	while (t--) {
		cin >> c;
		if (ans[c] == 0x3f3f3f3f)
			cout << -1 << endl;
		else
			cout << ans[c] << endl;
	}
}
 
int main() {
	solve();
	return 0;
}