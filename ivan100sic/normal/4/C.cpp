#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	map<string, int> mp;

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		if (mp[s] == 0) {
			cout << "OK\n";
			mp[s] = 1;
		} else {
			cout << s << (mp[s]++) << '\n';
		}
	}

}