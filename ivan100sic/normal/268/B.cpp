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

	long long s = 0;
	
	cin >> n;

	for (int i=1; i<=n; i++) {
		if (i == 1) {
			s += n;
		} else if (i < n) {
			s += i*(n-i+1) - (i-1);
		} else {
			s += 1;
		}
	}

	cout << s;
}