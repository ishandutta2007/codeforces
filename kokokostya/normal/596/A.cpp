#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arx;
	vector<int> ary;
	arx.resize(n);
	ary.resize(n);
	if (n == 1) { 
		for (int i = 0; i < n; i++) {
			cin >> arx[i] >> ary[i];
		}cout << -1; return 0; }
	if (n == 3 || n == 4) {
		for (int i = 0; i < n; i++) {
			cin >> arx[i] >> ary[i];
		}
		if (arx[0] == arx[2]) { swap(arx[0], arx[1]); swap(ary[0], ary[1]);
		}
		else { if (arx[0] == arx[1]) { swap(arx[0], arx[2]); swap(ary[0], ary[1]);
		} }
		cout << abs(arx[0] - arx[1]) * max(abs(ary[2] - ary[0]), abs(ary[1] - ary[0]));
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> arx[i] >> ary[i];
	}
	if (arx[0] == arx[1] || ary[0] == ary[1]) { cout << -1;}
	else { cout << abs(arx[0] - arx[1])*abs(ary[0] - ary[1]); }

	return 0;
}