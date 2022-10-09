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

long long solve(long long l, long long r, long long n, long long nl, long long nr) {
	if (r < nl || nr < l) {
		return 0;
	}
	if (l <= nl && nr <= r) {
		return n;
	}

	long long mid = (nl + nr) / 2;

	long long sum = 0;

	if (l <= mid && mid <= r) {
		sum += n % 2;
	}

	sum += solve(l, r, n/2, nl, mid-1);
	sum += solve(l, r, n/2, mid+1, nr);

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long n, l, r;

	cin >> n >> l >> r;

	long long list_size = 1;
	long long t = n;
	while (t > 1) {
		list_size = 2*list_size + 1;
		t /= 2;
	}

	cout << solve(l, r, n, 1, list_size);


}