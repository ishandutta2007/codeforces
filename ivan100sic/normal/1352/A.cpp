// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct _in {
	template<class T>
	operator T() {
		T x;
		cin >> x;
		return x;
	}
} in;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t = in;
	while (t--) {
		int n = in;
		vector<int> s;
		int p = 1;
		while (n) {
			if (int x = n % 10 * p)
				s.push_back(x);
			p *= 10;
			n /= 10;
		}

		cout << s.size() << '\n';
		for (int x : s)
			cout << x << ' ';
		cout << '\n';
	}
}