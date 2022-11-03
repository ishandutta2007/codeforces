#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector< pair<int, int> > arr(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') { arr[i].first = 1; }
		else {
			if (s[i] == 'D') { arr[i].first = -1; }
			else {
				if (s[i] == 'L') { arr[i].second = -1; }
				else { arr[i].second = 1; }
			}
		}
	
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		pair<int, int> res;
		res.first = arr[i].first;
		res.second = arr[i].second;
		for (int j = i + 1; j < n; j++) {
			res.first += arr[j].first;
			res.second += arr[j].second;
			if (res.first == 0 && res.second == 0) { ans++; }
		}
	}
	cout << ans;

	return 0;
}