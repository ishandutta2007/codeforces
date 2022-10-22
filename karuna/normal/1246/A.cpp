#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll N, p;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> p;
	for (int i=0; i<=32; i++) {
		ll tmp = N - i*p;
		if (tmp < 0) break;
		if (tmp < i) continue;

		int cnt = 0;
		while (tmp) {
			if (tmp&1) ++cnt;
			tmp/=2;
		}

		if (cnt <= i) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
}