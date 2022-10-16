#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dfs(vector<int>v, int c)
{
	if (v.size() <= 2)
		return v.size();
	vector<int>z, o;
	int i;
	for (i = 0; i < v.size(); i++)
	{
		if (v[i] & (1 << c))
		{
			o.push_back(v[i]);
		}
		else
		{
			z.push_back(v[i]);
		}
	}
	if (o.size() >= 2 && z.size() >= 2)
	{
		return max(dfs(o, c - 1), dfs(z, c - 1)) + 1;
	}
	else
	{
		if (o.size() > z.size())
			return dfs(o, c - 1)+z.size();
		else
		{
			return dfs(z, c - 1)+o.size();
		}
	}
}
int main()
{
	int N;
	cin >> N;
	vector<int>x;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		x.push_back(a);
	}
	cout << N - dfs(x, 29);
}