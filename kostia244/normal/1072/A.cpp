#include <bits/stdc++.h>

using namespace std;

int main() {
	int w, h, k, sum = 0;
	cin >> w >> h >> k;

	while(w > 1 && h > 1 && k > 0) {


		sum += (((2 *  w) + (2 * h)) - 4);

		w -= 4;
		h -= 4;
		k--;
	}

	cout << sum;

	return 0;
}