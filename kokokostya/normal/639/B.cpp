//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//int main() {
//	vector < long long > pw;
//	int n, k;
//	vector < long long > a, b;
//	cin >> n >> k;
//	a.resize(n + 1);
//	b.resize(n + 1);
//	pw.resize(n + 1);
//	pw[0] = 1;
//	for (int i = 1; i < n + 1; i++) {
//		pw[i] = 2 * pw[i - 1];
//	}
//	long long sum = 0;
//	for (int i = 0; i < n + 1; i++) {
//		cin >> a[i];
//		sum += a[i] * pw[i];
//	}
//	for (int i = 0; i < n + 1; i++) {
//		b[i] = sum - a[i] * pw[i];
//	}
//	int ans = 0;
//	for (int i = 0; i < n + 1; i++) {
//		if (b[i] % pw[i] == 0 && abs(b[i] / pw[i]) <= k && (i != n || abs(b[i] / pw[i] != 0)))
//			ans++;
//	}
//	cout << ans;
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, d, h;
	cin >> n >> d >> h;
	int now = 1;
	if (d > 2 * h || (n != 2 && d == 1)) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < h; i++) {
		cout << now << ' ' << now + 1 << '\n';
		now++;
	}
	if (h < d) {
		cout << "1 " << now + 1 << '\n';
		now++;
	}
	for (int i = now; i <= d; i++) {
		cout << now << ' ' << now + 1 << '\n';
		now++;
	}
	if (h > 1) {
		for (int i = now; i < n; i++) {
			cout << 2 << ' ' << now + 1 << '\n';
			now++;
		}
	}
	else {
		for (int i = now; i < n; i++) {
			cout << 1 << ' ' << now + 1 << '\n';
			now++;
		}
	}
	return 0;
}