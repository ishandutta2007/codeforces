#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m, c0, d0;
	cin >> n >> m >> c0 >> d0;
	vector<int> canEarn(n + 1);
	for (int i = n - c0; i >= 0; i--) {
		canEarn[i] = canEarn[i + c0] + d0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int cnt = a / b; cnt != 0; cnt--) {
			for (int j = 0; j <= n - c; j++) {
				canEarn[j] = max(canEarn[j], canEarn[j + c] + d);
			}
		}
	}
	cout << canEarn[0] << endl;
	return 0;
}