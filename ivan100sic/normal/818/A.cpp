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

	long long n, k;
	cin >> n >> k;
	long long winners = n/2;

	long long medals = winners / (k+1);

	long long pohvale = medals * k;

	cout << medals << ' ' << pohvale << ' ' << (n - medals - pohvale);
}