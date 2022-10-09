#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
int p;

struct aparat {
	int brzina, kolicina;

	bool operator< (const aparat& other) const {
		return kolicina * other.brzina < other.kolicina * brzina;
	}

} a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> p;
	for (int i=1; i<=n; i++) {
		cin >> a[i].brzina >> a[i].kolicina;
	}

	long long total_brzina = 0;
	for (int i=1; i<=n; i++) {
		total_brzina += a[i].brzina;
	}

	if (total_brzina <= p) {
		cout << -1;
		return 0;
	}

	sort(a+1, a+n+1);

	double l=0, r=1e18;
	int steps = 80;
	while (steps--) {
		double m = (l+r) / 2;

		// hocu da izdrze m sekundi
		// kolika mi snaga chargeovanja treba za to?
		double pw = 0.0;
		for (int i=1; i<=n; i++) {
			double preko = a[i].brzina * m - a[i].kolicina;
			if (preko > 0.0) {
				// moram da ga punim brzinom
				pw += preko / m;
			}
		}

		cerr << pw << ' ' << p << '\n';

		if (pw > p) {
			r = m;
		} else {
			l = m;
		}
	} 

	cout.precision(20);
	cout << fixed << l;


}