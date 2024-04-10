#include <iostream>
using namespace std;

typedef long long int64;

int sign(int64 p) {
	return (p > 0) ? 1 : ((p < 0) ? -1 : 0);
}

int main(void) {
	int64 x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	int answer = 0;
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (sign(a * x1 + b * y1 + c) * sign(a * x2 + b * y2 + c) == -1)
			++answer;
	}
	cout << answer << endl;
}