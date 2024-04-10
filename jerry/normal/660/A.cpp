#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<int> sol;

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		int x; scanf("%d", &x);
		nums.push_back(x);
	}
	sol.push_back(nums[0]);
	for (int i = 1;i < n;i++)
	{
		if (__gcd(nums[i-1], nums[i]) != 1)
			sol.push_back(1);
		sol.push_back(nums[i]);
	}
	printf("%d\n", sol.size()-nums.size());
	for (int u: sol) printf("%d ", u);
	printf("\n");
	return 0;
}