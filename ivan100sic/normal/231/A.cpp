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

	int n;
	cin >> n;
	int cc = 0;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a+b+c >= 2) {
			cc++;
		}
	}
	cout << cc;
}