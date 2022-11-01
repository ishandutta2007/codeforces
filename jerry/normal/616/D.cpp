#include <bits/stdc++.h>
using namespace std;

map<int, int> all;
queue<int> have;
int S, E, sf, n, k, x;

int main()
{
	E = -1;
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &x);
		have.push(x);
		all[x]++;
		while (all.size() > k)
		{
			if (--all[have.front()] == 0)
				all.erase(have.front());
			have.pop();
			sf++;
		}
		if (i-sf > E-S)
			S = sf, E = i;
	}
	printf("%d %d\n", S+1, E+1);
	return 0;
}