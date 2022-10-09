#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int c[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		c[x]++;
	}

	int sol = 0;

	// grupa od 4, nemamo izbora
	sol += c[4];
	c[4] = 0;

	// sve parove 3,1 koje mozemo da napravimo
	int x = min(c[3], c[1]);
	sol += x;
	c[3] -= x;
	c[1] -= x;

	// sve ostale 3
	sol += c[3];
	c[3] = 0;

	// sada imamo samo 1, 2
	sol += (2*c[2] + c[1] + 3) / 4;

	cout << sol;
}