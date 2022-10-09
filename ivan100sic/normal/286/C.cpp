#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, t;
int a[1000005];
int q[1000005];
basic_string<int> st;

void no() {
	cout << "NO\n";
	exit(0);
}

void match(int x) {
	while (st.size() && a[st.back()] != a[x]) {
		int t = st.back();
		st.pop_back();
		match(t);
	}

	if (st.size() && a[st.back()] == a[x]) {
		q[st.back()] = 1;
		st.pop_back();
		q[x] = -1;
		return;
	} else {
		no();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	a[0] = 1123123123;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	a[n+1] = 1123123123;
	q[n+1] = -1;

	cin >> t;
	for (int i=1; i<=t; i++) {
		int x;
		cin >> x;
		q[x] = -1;
	}

	for (int i=0; i<=n+1; i++) {
		if (q[i] == -1) {
			match(i);
		} else {
			st += i;
		}
	}

	cout << "YES\n";
	for (int i=1; i<=n; i++)
		cout << a[i]*q[i] << ' ';
	cout << '\n';
}