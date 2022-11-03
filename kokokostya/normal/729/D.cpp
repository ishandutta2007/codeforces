#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> d;
	int now = -1;
	int f = 0;
	vector<int> st;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '1') {
			if (i - now - 1 >= b) {
				d.push_back(i - now - 1);
				st.push_back(now + 1);
			}
			f += (i - now - 1) / b;
			now = i;
		}
	}
	if (n - 1 - now >= b) {
		d.push_back(n - 1 - now);
		st.push_back(now + 1);
	}
	f += (n - 1 - now) / b;
	cout << f - a + 1 << '\n';
	int will = f - a + 1;
	for (int i = 0; i < d.size(); i++) {
		int g = st[i];
		while (will && g + d[i] - 1 >= st[i] + b - 1) {
			cout << st[i] + b << ' ';
			will--;
			st[i] += b;
		}
	}
	return 0;
}