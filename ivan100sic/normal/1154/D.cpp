#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, b, a, bb, aa;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> b >> a;
	bb = b;
	aa = a;
	int reach = 0;
	for (int i=1; i<=n; i++) {
		int s;
		cin >> s;
		if (s == 0) {
			if (aa > 0) {
				aa--;
			} else if (bb > 0) {
				bb--;
			} else {
				break;
			}
		} else {
			if (bb > 0 && aa < a) {
				bb--;
				aa++;
			} else if (aa > 0) {
				aa--;
			} else {
				break;
			}
		}
		reach = i;
	}
	cout << reach << '\n';
}