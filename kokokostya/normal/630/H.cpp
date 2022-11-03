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
	long long res;
	res = cn(n, 5) * n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
	cout << res;
	return 0;
}