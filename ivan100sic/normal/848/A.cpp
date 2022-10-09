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

	int n;
	cin >> n;

	string s = "z";
	char c = 'a';

	while (n > 0) {
		int x = 0;
		while (x*(x+1) / 2 <= n) {
			x++;
		}
		for (int i=1; i<=x; i++) {
			s += c;
		}
		n -= x * (x-1) / 2;
		c++;
	}
	cout << s;
}