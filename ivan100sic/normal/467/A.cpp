#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, c=0;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (b - a >= 2) {
			c++;
		}
	}
	cout << c;
}