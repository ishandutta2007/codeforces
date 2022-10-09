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

	int a[105], n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++) {
		cout << a[i] << ' ';
	}

}