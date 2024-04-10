#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long k;
vector<int> a;

long long getSum(int p) {
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += min(a[i], p);
	}
	return res;
}

int main(void) {
	scanf("%d%I64d", &n, &k);
	a.resize(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum < k) {
		printf("-1\n");
		return 0;
	} else if (sum == k) {
		printf("\n");
		return 0;
	}
	int l = 0, r = 1000000001;
	while (r - l != 1) {
		int m = (r + l) / 2;
		if (getSum(m) > k)
			r = m;
		else
			l = m;
	}
	k -= getSum(l);
	vector<int> res1, res2;
	int i;
	for (i = 0; k != 0; i++) {
		if (a[i] <= l)
			continue;
		--k;
		if (a[i] > l + 1)
			res2.push_back(i + 1);
	}
	for ( ; i < n; i++) {
		if (a[i] <= l)
			continue;
		res1.push_back(i + 1);
	}
	res1.insert(res1.end(), res2.begin(), res2.end());
	for (int i = 0; i < (int)res1.size(); i++) {
		if (i)
			printf(" ");
		printf("%d", res1[i]);
	}
	printf("\n");
	return 0;
}