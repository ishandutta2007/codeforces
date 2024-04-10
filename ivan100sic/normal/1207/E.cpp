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

	cout << "?";
	for (int i=1; i<=100; i++)
		cout << ' ' << 128*i;
	cout << '\n' << flush;
	int x, y;
	cin >> x;
	cout << "?";
	for (int i=0; i<100; i++)
		cout << ' ' << i;
	cout << '\n' << flush;
	cin >> y;
	cout << "! " << (y & 0b11111110000000) + (x & 0b1111111) << '\n' << flush;
}