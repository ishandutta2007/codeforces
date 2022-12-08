#include <iostream>
using namespace std;

int main() {
	int n, A, B, C, T;
	cin >> n >> A >> B >> C >> T;
	int ans = 0;
	int h;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (h > T) continue;
		if (B > C) ans += A;
		else ans += A + (C - B) * (T - h);
	}
	cout << ans << "\n";
}