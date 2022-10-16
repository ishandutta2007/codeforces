#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int>nums;
int a[300100];
long long tree[1 << 20];
int treeN, M, K;
long long quarry(int l, int r, int L, int R, int idx)
{
	if (l <= L && R <= r)
	{
		return tree[idx];
	}
	if (L > r || R < l)
	{
		return 0;
	}
	return quarry(l, r, L, (L + R) / 2, idx * 2) + quarry(l, r, (L + R) / 2 + 1, R, idx * 2 + 1);
}
void update(int idx, long long changevalue)
{
	idx += treeN;
	tree[idx] = changevalue;
	while (idx != 1)
	{
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}
signed main()
{
	cin >> N;
	int i;
	for (treeN = 1; treeN < N; treeN *= 2);
	for (i = 0; i < N; i++)
	{
		cin >> a[i];
		update(i, 1);
	}
	for (i = 0; i < N; i++)
	{
		int b;
		cin >> b;
		nums.push_back(b);
	}
	sort(nums.begin(), nums.end());
	for (i = 0; i < N; i++)
	{
		int start = 0;
		int end = N - 1;
		int j;
		int nowv = 0;
		for (j = 29; j >= 0; j--)
		{
			int lower = nowv + (1 << j);
			int mini = lower_bound(nums.begin(), nums.end(), lower)-nums.begin()-1;
			int oldstart = start;
			int oldend = end;
			nowv += (1 << j) & a[i];
			if ((1 << j) & a[i])
				start = mini + 1;
			else
				end = mini;
			if (start > end || !quarry(start, end, 0, treeN - 1, 1))
			{
				start = oldstart;
				end = oldend;
				if ((1 << j) & a[i])
					end = mini;
				else
					start = mini + 1;
				nowv += ((1 << j) & a[i]) ? (-(1 << j)) : (1 << j);
			}
			while (!tree[start + treeN])
				start++;
			while (!tree[end + treeN])
				end--;
		}
		cout <<(a[i]^nums[start])<<' ';
		update(start, 0);
	}
}