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
	long long int t;
	set<long long int> se;
	int ans = -1;
	se.insert(-1);
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (se.find(t - 1) == se.end()) {
			ans = i + 1;
			break;
		}
		else {
			se.insert(t);
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}