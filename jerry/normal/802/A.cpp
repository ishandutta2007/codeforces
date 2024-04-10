#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

bool opened[100001];
int occurrences[200001];
int nums[200001];
int left[200001];
int n;
int c;
int k;
int remain;
int ans;

struct comp
{
	bool operator() (const int a, const int b)
	{
		return (occurrences[left[a]] > occurrences[left[b]]);
	}
};

bool pred(const int a, const int b)
{
	if (nums[a] != nums[b])
		return (nums[a] < nums[b]);
	return (a < b);
}

set<int, comp> pq;

int main()
{
	scanf("%d%d", &n, &k);
	c = n;
	remain = k;
	for (int i = 0;i < n;i++)
	{
		scanf("%d", nums+i);
		nums[i]--;
		occurrences[i] = i;
	}
	for (int i = 0;i < c;i++)
	{
		nums[i+n] = i;
		occurrences[i+n] = i+n;
	}
	sort(occurrences, occurrences+(n+c), pred);
	int ind = 0;
	left[ind++] = 0;
	for (int i = 1;i < n+c;i++) if (nums[occurrences[i]] != nums[occurrences[i-1]])
		left[ind++] = i;
	for (int i = 0;i < n;i++)
	{
		if (opened[nums[i]])
		{
			pq.erase(nums[i]);
			left[nums[i]]++;
			pq.insert(nums[i]);
			continue;
		}
		ans++;
		if (remain > 0)
			remain--;
		else
		{
			opened[*pq.begin()] = false;
			pq.erase(pq.begin());
		}
		opened[nums[i]] = true;
		left[nums[i]]++;
		pq.insert(nums[i]);
	}
	printf("%d\n", ans);
	return 0;
}