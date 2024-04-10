#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool dist(int x) {
	int c[10] = {0};
	for (int i=0; i<4; i++) {
		c[x % 10]++;
		x /= 10;
	}
	return *max_element(c, c+10) == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x;
	cin >> x;
	x++;
	while (!dist(x)) {
		x++;
	}
	cout << x;
}