#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void rev(bitset<4>& b) {
	int t = b[0];
	b[0] = b[3];
	b[3] = t;

	t = b[1];
	b[1] = b[2];
	b[2] = t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// i just read the editorial...
	// i don't like these contests

	int x;
	cin >> x;
	bitset<4> b(x), a;
	rev(b);
	x = b.to_ulong();
	b = x-1;
	rev(b);
	cout << b.to_ulong() << '\n';
}