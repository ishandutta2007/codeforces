#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

long long f(long long n) {
	if (n == 1)
		return 1;
	else {
		vector< pair<long long, int> > cnt;
		for (int i = 2; i * 1ll * i <= n; i++) {
			if (n % i == 0) {
				cnt.push_back({ i, 1 });
				n /= i;
				while (n % i == 0) {
					n /= i;
					cnt[cnt.size() - 1].second++;
				}
			}
		}
		if (n != 1)
			cnt.push_back({ n, 1 });
		long long ans = 1;
		for (pair<long long, int> i : cnt) {
			long long res = 1;
			for (int j = 0; j < i.second; j++)
				res *= i.first;
			res -= res / i.first;
			ans *= res;
		}
		return ans;
	}
}

long long F(long long k, long long n) {
	if (k == 1)
		return f(n);
	long long res = F(k - 2, n);
	if (res == 1)
		return 1;
	return f(res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, k;
	cin >> n >> k;
	if (k > 1e6) {
		cout << 1;
		return 0;
	}
	if (k % 2 == 0)
		k--;
	cout << F(k, n) % mod;
	return 0;
}