#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll solveNaive(int c, int h1, int h2, int w1, int w2) {
	if (w1 < w2) {
		swap(w1, w2);
		swap(h1, h2);
	}
	ll result = 0;
	for (int i = 0; w1 * i <= c; ++i) {
		result = max(result, ll(h1) * i + (c - w1 * i) / w2 * ll(h2));
	}
	return result;
}

ll solveSmart(int c, int h1, int h2, int w1, int w2) {
	if (h1 * ll(w2) < h2 * ll(w1)) {
		swap(h1, h2);
		swap(w1, w2);
	}
	ll result = 0;
	for (int i = 0; i < max(w1, w2) && i * w2 <= c; ++i) {
		result = max(result, i * ll(h2) + (c - w2 * i) / w1 * ll(h1));
	}
	return result;
}

int main(void) {
	int c, h1, h2, w1, w2;
	cin >> c >> h1 >> h2 >> w1 >> w2;
	if (max(w1, w2) > 30000) {
		cout << solveNaive(c, h1, h2, w1, w2) << endl;
	}
	else {
		cout << solveSmart(c, h1, h2, w1, w2) << endl;
	}
}