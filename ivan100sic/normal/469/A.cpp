#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int c[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, p;
	cin >> n;

	for (int i=0; i<2; i++) {
		cin >> p;
		while (p--) {
			int x;
			cin >> x;
			c[x] = 1;
		}
	}

	int f = accumulate(c+1, c+n+1, 0);
	
	cout << (f == n ? "I become the guy.\n" : "Oh, my keyboard!\n");
}