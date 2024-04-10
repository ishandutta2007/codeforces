#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > nums;
int val[200005];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", val+i), nums.push_back(make_pair(val[i]+i, val[i]));
	sort(nums.begin(), nums.end());
	for (int i = 0;i < n;i++)
		nums[i].second = nums[i].first - i;
	bool ok = nums[0].second >= 0;
	for (int i = 1;i < n;i++) if (nums[i].second < nums[i-1].second)
		ok = false;
	if (ok) for (int i = 0;i < n;i++) printf("%d%c", nums[i].second, " \n"[i==n-1]);
	else printf(":(\n");
	return 0;
}