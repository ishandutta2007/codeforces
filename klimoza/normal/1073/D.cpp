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
	ll n, t;
	cin >> n >> t;
	ll sum = 0;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll ans = t / sum * n;
	t %= sum;
	bool fl = true;
	ll cnt;
	while (fl) {
		fl = false;
		cnt = 0;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (t >= a[i]) {
				t -= a[i];
				ans++;
				fl = true;
				cnt++;
				sum += a[i];
			}
		}
		if (sum == 0) break;
		ans += t / sum * cnt;
		t -= sum * (t / sum);
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}