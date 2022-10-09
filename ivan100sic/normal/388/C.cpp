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

	basic_string<int> b;
	int n, p=0, q=0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		for (int i=1; i<=x; i++) {
			int z;
			cin >> z;
			if (i < x+1-i)
				p += z;
			else if (i > x+1-i)
				q += z;
			else
				b += z;
		}
	}
	sort(b.begin(), b.end(), greater<int>());
	for (int i=0; i<(int)b.size(); i++)
		if (i % 2)
			q += b[i];
		else
			p += b[i];
	cout << p << ' ' << q << '\n';
}