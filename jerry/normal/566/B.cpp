#include <bits/stdc++.h>
using namespace std;

#define a first.first
#define b first.second.first
#define c first.second.second
#define id second

typedef pair<pair<int, pair<int, int> >, int> obj;

multiset<obj> all;
vector<int> sol;
int sz[30005];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < 4*n;i++)
	{
		int A, B, C; scanf("%d%d%d", &A, &B, &C);
		if (C == A) swap(B, C);
		all.insert(make_pair(make_pair(A, make_pair(B, C)), i+1));
		sz[A]++;
	}
	while (!all.empty())
	{
		bool fl = true;
		for (auto it = all.begin();it != all.end();)
			if (it->c == it->a)
			{
				if (sz[it->a] < 9)
				{
					sz[it->a]++;
					sol.push_back(it->id);
					it = all.erase(it);
					fl = false;
				} else
					it++;
			} else if (it->b == it->a)
			{
				if (sz[it->c] < 9)
				{
					sz[it->c]++;
					sol.push_back(it->id);
					it = all.erase(it);
					fl = false;
				} else
					it++;
			} else if (it->b == it->c)
			{
				if (sz[it->b] < 8)
				{
					sz[it->a]--;
					sz[it->b] += 2;
					sol.push_back(it->id);
					it = all.erase(it);
					fl = false;
				} else
					it++;
			} else
			{
				if (sz[it->b] < 9 && sz[it->c] < 9)
				{
					sz[it->a]--;
					sz[it->b]++;
					sz[it->c]++;
					sol.push_back(it->id);
					it = all.erase(it);
					fl = false;
				} else
					it++;
			}
		if (fl)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int u: sol) printf("%d ", u);
	printf("\n");
	return 0;
}