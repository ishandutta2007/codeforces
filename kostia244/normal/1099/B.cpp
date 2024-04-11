#include <bits/stdc++.h>
using namespace std;

int xs = 1, ys = 1, n;
int main() {
	cin >> n;
	while(n > (xs * ys)) {
		xs++;
		if(n <= (xs * ys))
			break;
		ys++;
	}
	cout << (xs + ys);
	return 0;
}