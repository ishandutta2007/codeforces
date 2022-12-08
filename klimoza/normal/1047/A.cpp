#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;


int main() {
	int n;
	cin >> n;
	if (n % 3 == 0) {
		cout << "1 1 " << n - 2 << "\n";
	}
	else {
		cout << "1 2 " << n - 3 << "\n";
	}
	//system("pause");
	return 0;
}