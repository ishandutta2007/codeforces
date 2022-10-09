#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b, s;
	int n;
	cin >> a >> b;
	n = a.size();
	s.resize(n);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<char>());

	a.resize(n - n / 2);
	b.resize(n / 2);

	int al=0, ar=a.size()-1;
	int bl=0, br=b.size()-1;

	int sl=0, sr=n-1;

	auto inv = [&]() {
		return b[bl] <= a[al];
	};

	for (int i=0; i<n; i++) {
		if (inv()) {
			if (i % 2 == 0) {
				s[sr--] = a[ar--];
			} else {
				s[sr--] = b[br--];
			}
		} else if (i % 2 == 0) {
			s[sl++] = a[al++];
		} else {
			s[sl++] = b[bl++];
		}
	}

	cout << s;

}