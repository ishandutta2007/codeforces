#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp(string s, string t) {
	return s + t < t + s;
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}

	return 0;
}