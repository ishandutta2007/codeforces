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

#ifdef LOCAL
	auto& input = cin;
	auto& output = cout;
#else
	ifstream input("input.txt");
	ofstream output("output.txt");
#endif

	ll t, k;
	input >> t >> k;
	while (t--) {
		ll x, y;
		input >> x >> y;
		x--, y--;
		ll l = min(x, y) / (k+1);
		ll r = min(x, y) % (k+1);

		bool prvi;

		if (k == 1)
			prvi = r == k || (x+y) % 2;
		else
			prvi = r == k || (x+y+l) % 2;


		if (prvi)
			output << "+\n";
		else
			output << "-\n";	
	}
}