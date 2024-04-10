#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	set<int> s;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	int z = -1;
	if (s.size() > 3) {
		z = -1;
	} else if (s.size() == 3) {
		if (*++s.begin() - *s.begin() == *++ ++s.begin() - *++s.begin()) {
			z = *++s.begin() - *s.begin();
		} else {
			z = -1;
		}
	} else if (s.size() == 2) {
		if ((*++s.begin() - *s.begin()) % 2 == 0) {
			z = (*++s.begin() - *s.begin()) / 2;
		} else {
			z = (*++s.begin() - *s.begin());
		}
	} else {
		z = 0;
	}
	cout << z << '\n';
}