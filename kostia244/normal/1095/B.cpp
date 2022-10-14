#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n <= 2) {
		cout << 0;
		return 0;
	}

	vector<int> a(n);
	for(auto& i : a)
		cin >> i;
	sort(a.begin(), a.end());
	cout << min(abs(a[a.size() - 1] - a[1]), abs(a[a.size() - 2] - a[0]));
	return 0;
}