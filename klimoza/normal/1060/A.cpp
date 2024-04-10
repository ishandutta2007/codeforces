#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	int um = 0;
	int ei = 0;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '8') {
			ei++;
		}
		else {
			um++;
		}
	}
	for (int i = ei; i >= 0; i--) {
		if (um / 10 >= ei) {
			cout << ei << "\n";
			break;
		}
		else {
			ei--;
			um++;
		}
	}
	//system("pause");
	return 0;
}