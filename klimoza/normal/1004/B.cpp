#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cout << "0";
		}
		else {
			cout << "1";
		}
	}
	//system("pause");
	return 0;
}