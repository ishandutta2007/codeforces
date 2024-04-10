#include <cstdio>
#include <algorithm>

using namespace std;

int om[100][100];
int tmp;
int req;
int k;
int r;
int c;

int getans()
{
	int ans = 2147483647;
	for (int key = 0;key < r;key++)
	{
		req = 0;
		for (int i = 0;i < r;i++)
		{
			tmp = 0;
			for (int j = 0;j < c;j++)
				tmp += (om[i][j] == om[key][j]);
			req += min(tmp, c-tmp);
		}
		ans = min(ans, req);
	}
	for (int key = 0;key < c;key++)
	{
		req = 0;
		for (int i = 0;i < c;i++)
		{
			tmp = 0;
			for (int j = 0;j < r;j++)
				tmp += (om[j][i] == om[j][key]);
			req += min(tmp, r-tmp);
		}
		ans = min(ans, req);
	}
	return ans;
}

int main()
{
	int ans = 2147483647;
	scanf("%d%d%d", &r, &c, &k);
	for (int i = 0;i < r;i++) for (int j = 0;j < c;j++)
		scanf("%d", &om[i][j]);
	if (r <= 10)
	{ // have enough changes, might want to just modify every column
		int orig = 0;
		for (int i = 0;i < r;i++)
			orig += (om[i][0] << i);
		for (int key = 0;key < (1<<r);key++)
		{
			int temp = 0;
			for (int i = 0;i < r;i++)
			{
				temp += (((orig & (1 << i)) ^ (key & (1 << i))) >> i);
				om[i][0] = (key & (1 << i)) >> i;
			}
			temp += getans();
			if (temp < ans)
				ans = temp;
		}
		if (ans <= k)
			printf("%d\n", ans);
		else
			printf("-1\n");
		return 0;
	}
	ans = getans();
	if (ans <= k)
		printf("%d\n", ans);
	else
		printf("-1\n");
	return 0;
}