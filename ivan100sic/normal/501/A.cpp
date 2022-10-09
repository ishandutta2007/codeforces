#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int skor(int p, int t) {
	return max(3*p / 10, p - p/250 * t);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = skor(a, c);
	int y = skor(b, d);
	if (x > y)
		cout << "Misha\n";
	else if (x == y)
		cout << "Tie\n";
	else
		cout << "Vasya\n";
}