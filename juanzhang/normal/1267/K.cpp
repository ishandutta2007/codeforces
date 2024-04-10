#include <bits/stdc++.h>
using namespace std;

long long solve(vector <int> a) {
	long long ans = 1;
	int pos = 0;
	for (int i = 0; i < a.size(); i++) {
		while (pos < a.size() && a[pos] <= i + 1) pos++;
		ans *= (pos - i);
	}
	for (int i = 0; i < a.size(); i++) {
		long long pw = 1;
		int nxt = i;
		while (nxt < a.size() && a[nxt] == a[i]) nxt++, pw *= (nxt - i);
		ans /= pw;
		i = nxt - 1;
	}
	return ans;
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		long long x; cin >> x;
		vector <int> a;
		for (int i = 2; x; i++) {
			a.push_back(x % i), x /= i;
		}
		sort(a.begin(), a.end());
		long long ans = solve(a);
		if (a[0] == 0) a.erase(a.begin()), ans -= solve(a);
		printf("%lld\n", ans - 1);
	}
	return 0;
}