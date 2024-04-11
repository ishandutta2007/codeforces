#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int mn = 1e6 + 66;
int px[mn];
void solve() {
	int n, t, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		px[i] = px[i-1]^i;
	}
	for(int i = 1; i <= n; i++) {
		cin >> t, ans ^= t;
		ans^= ((n/i)&1)*px[i-1];
		ans^= px[n%i];
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}