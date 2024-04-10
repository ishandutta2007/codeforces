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
	int p=0, q=0;
	for (int a=1; a<n-a; a++) {
		if (__gcd(a, n-a) == 1) {
			p = a;
			q = n-a;
		}
	}
	cout << p << ' ' << q << '\n';
}