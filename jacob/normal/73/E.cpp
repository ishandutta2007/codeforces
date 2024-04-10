#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int MAXN = 5000000;

int main(void) {
	vector<char> isPrime(MAXN, 1);
	isPrime[1] = isPrime[0] = 0;
	for (int i = 2; i*i < MAXN; i++) {
		if (!isPrime[i])
			continue;
		for (int j = i * i; j < MAXN; j+=i)
			isPrime[j] = 0;
	}
	int count = 100000;
	for (int i = 2; i < MAXN; i++) {
		if (isPrime[i])
			--count;
	}
	assert(count <= 0);
	int n, x;
	scanf("%d%d", &n, &x);
	if (x == 2)
	{
		printf("0\n");
		return 0;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			printf("1\n");
			return 0;
		}
		if (a < MAXN && isPrime[a] && a < x) {
			++res;
			isPrime[a] = 0;
		}
	}
	if (x >= MAXN) {
		printf("-1\n");
		return 0;
	}
	for (int i = 2; i < x; i++) {
		if (isPrime[i]) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", res);
	return 0;
}