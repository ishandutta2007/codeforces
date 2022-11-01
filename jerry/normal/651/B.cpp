#include <bits/stdc++.h>
using namespace std;

vector<int> x[2];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		int a; scanf("%d", &a);
		x[0].push_back(a);
	}
	sort(x[0].begin(), x[0].end());
	while (x[0].size())
	{
		reverse(x[0].begin(), x[0].end());
		for (int last = -1;!x[0].empty();x[0].pop_back())
			if (x[0].back() > last)
				last = x[0].back();
			else
				x[1].push_back(x[0].back());
		swap(x[0], x[1]);
		x[1].clear();
		n--;
	}
	cout << n << endl;
	return 0;
}