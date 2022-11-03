#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a - 1;
		cout << ((sum + 1) % 2) + 1 << '\n';
	}
	return 0;
}