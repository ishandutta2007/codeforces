#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>

using namespace std;


int main() {
	int n, ans;
	cin >> n;
	bool fl = false;
	for (int i = 0; i < n; i++) {
		cin >> ans;
		if (ans == 1) {
			fl = true;
			break;
		}
	}
	if (fl) {
		cout << "HARD\n";
	}
	else {
		cout << "EASY\n";
	}
	//system("pause");
	return 0;
}