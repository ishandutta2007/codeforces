#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	int n, m;
	cin >> n >> m;
	int mod = 998244353;
	vector<ll> wo(n + 1);
	wo[0] = 1;
	for (int i = 1; i <= n; i++) {
		wo[i] = (wo[i - 1] * 2) % mod;
	}
	string st1, st2;
	cin >> st1 >> st2;
	int cur = 0;
	int t1 = 0;
	int t2 = 0;
	if (m > n) {
		for (int i = 0; i < m - n; i++) {
			if (st2[i] == '1') cur++;
		}
		t2 = m - n;
	}
	if (n > m) {
		t1 = n - m;
	}
	ll ans = 0;
	for (int i = 0; i < min(n, m); i++) {
		if (st2[i + t2] == '1') cur++;
		if (st1[i + t1] == '1') {
			ans += (cur * wo[n - t1 - i - 1]) % mod;
			ans %= mod;
		}
	}
	cout << ans << "\n";
	//system("pause");  
	return 0;
}