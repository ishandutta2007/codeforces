#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	string a, b, c;
	for (int i=0; i<m; i++) {
		a += '#';
		b += (i == m-1) ? '#' : '.';
		c += i ? '.' : '#';
	}

	string s[4] = {a, b, a, c};
	for (int i=0; i<n; i++) {
		cout << s[i % 4] << '\n';;
	}

}