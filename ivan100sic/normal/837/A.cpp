#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, sol = 0;
	cin >> n;
	string s;
	while (cin >> s) {
		int vol = 0;
		for (char x : s) {
			if (x >= 'A' && x <= 'Z') {
				vol++;
			}
		} 
		sol = max(sol, vol);
	}
	cout << sol;

}