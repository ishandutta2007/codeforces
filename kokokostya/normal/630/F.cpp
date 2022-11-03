#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long cn(long long n, long long k) {
	long long res = 1;
	long long j = 2;
	for (long long i = n - k + 1; i <= n; i++) {
		res *= i;
		if (res % j == 0 && j <= k) {
			res /= j;
			j++;
		}
	}
	for (long long i = j; i <= k; i++) {
		res /= i;
	}
	return res;

}

int main() {
	long long n;
	cin >> n;
	long long ans = 0;
	ans += cn(n, 5);
	ans += cn(n, 6);
	ans += cn(n, 7);
	cout << ans;
	return 0;
}