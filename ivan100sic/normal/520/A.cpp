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

	string s;
	int n;
	cin >> n >> s;
	set<int> a;

	int lo = 0, up = 0;

	for (char x : s) {
		a.insert(x & 31);
	}

	cout << (a.size() == 26 ? "YES" : "NO");

}