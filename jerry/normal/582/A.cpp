#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	while (a && b)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return a+b;
}

int main()
{
	int n, N; scanf("%d", &n); N = n*n;
	multiset<int> stuff;
	for (int i = 0;i < N;i++)
	{
		int x; scanf("%d", &x);
		stuff.insert(x);
	}
	vector<int> ans;
	for (int i = 0;i < n;i++)
	{
		ans.push_back(*stuff.rbegin());
		for (int j = 0;j < ((int)ans.size());j++)
		{
			stuff.erase(stuff.find(gcd(ans[j], ans.back())));
			if (j+1 != ans.size())
				stuff.erase(stuff.find(gcd(ans[j], ans.back())));
		}
	}
	for (int x: ans) printf("%d ", x);
	printf("\n");
	return 0;
}