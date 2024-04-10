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

	int n, m, a, b, v=1e9;
	cin >> n >> m >> a >> b;

	for (int i=0; i<=1000; i++) {
		int s = n - m*i;
		if (s < 0) {
			s = 0;
		}
		v = min(v, a*s + b*i);
	}

	cout << v;

}