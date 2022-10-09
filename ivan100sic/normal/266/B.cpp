#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, t;
	string s;
	cin >> n >> t >> s;

	while (t--) {
		vector<int> swaps;
		for (int i=0; i<=n-2; i++) {
			if (s[i] == 'B' && s[i+1] == 'G') {
				swaps.push_back(i);
			}
		}
		for (int x : swaps) {
			swap(s[x], s[x+1]);
		}
	}

	cout << s;
}