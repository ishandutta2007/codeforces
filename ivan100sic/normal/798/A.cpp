#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();

	for (int i=0; i<n; i++) {
		for (char x='a'; x<='z'; x++) {
			string p = s;
			if (p[i] == x) {
				continue;
			}
			p[i] = x;
			string q = p;
			reverse(q.begin(), q.end());
			if (p == q) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}