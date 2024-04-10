#include <bits/stdc++.h>
using namespace std;
int nums[1000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", nums + i);
	sort(nums, nums + n);
	printf("%d", nums[(n - 1) / 2]);
	getchar(); getchar();
}