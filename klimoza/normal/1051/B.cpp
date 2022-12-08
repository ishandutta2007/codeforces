#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	long long int l, r;
	cin >> l >> r;
	cout << "YES\n";
	for (long long int i = l; i <= r; i += 2) {
		cout << i << " " << i + 1 << "\n";
	}
	//system("pause");
	return 0;
}