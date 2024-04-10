// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[300005];
basic_string<int> e[300005];
int d[300005], n;

template<class F>
void run(const vector<int>& v, F cmp) {
	vector<int> st;
	for (int x : v) {
		while (st.size() && cmp(a[st.back()], a[x])) {
			int y = st.back();
			st.pop_back();
			e[min(y, x)] += max(y, x);
		}
		while (st.size() && a[st.back()] == a[x]) {
			int y = st.back();
			st.pop_back();
			e[min(y, x)] += max(y, x);
		}
		st.push_back(x);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		d[i] = -1;
	}

	vector<int> v(n);
	iota(begin(v), end(v), 0);
	run(v, less<int>());
	run(v, greater<int>());
	reverse(begin(v), end(v));
	run(v, less<int>());
	run(v, greater<int>());

	basic_string<int> q = {0};
	size_t qs = 0;
	d[0] = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (int y : e[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				q += y;
			}
		}
	}
	cout << d[n-1] << '\n';
}