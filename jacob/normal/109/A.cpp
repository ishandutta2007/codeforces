#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> from(1000001, -1);
	from[0] = 0;
	for (int i = 4; i <= 1000000; i+=4) {
		from[i] = 4;
	}
	for (int i = 0; i + 7 <= 1000000; i++) {
		if (from[i] != -1) {
			from[i+7] = 7;
		}
	}
	int n;
	cin >> n;
	vector<char> res;
	if (from[n] == -1) {
		cout << -1;
		return 0;
	}
	while (n != 0) {
		res.push_back(from[n] + '0');
		n -= from[n];
	}
	reverse(res.begin(), res.end());
	cout << string(res.begin(), res.end()) << endl;
	return 0;
}