#include <bits/stdc++.h>
using namespace std;

map<unsigned, vector<vector<int> > > has;
int n, a[1000005], b[1000005];
bool vi[1000005];

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", a+i), a[i]--;
	for (int i = 0;i < n;i++) if (!vi[i])
	{
		vector<int> here;
		here.push_back(i), vi[i] = true;
		for (int j = a[i];j != i;j = a[j]) here.push_back(j), vi[j] = true;
		has[here.size()].push_back(here);
	}
	for (auto it = has.begin();it != has.end();it++)
	{
		int sz = it->first;
		if (sz&1) for (auto it2 = it->second.begin();it2 != it->second.end();it2++)
		{
			int off = (sz+1)>>1;
			for (int i = 0;i < sz;i++) b[(*it2)[i]] = (*it2)[(i+off)%sz];
		} else
		{
			if (it->second.size()&1)
			{
				printf("-1\n");
				return 0;
			}
			for (auto it2 = it->second.begin();it2 != it->second.end();it2++)
			{
				auto it3 = it2; it3++;
				for (int i = 0;i < sz;i++)
				{
					b[(*it2)[i]] = (*it3)[i];
					b[(*it3)[i]] = (*it2)[(i+1)%sz];
				}
				it2 = it3;
			}
		}
	}
	for (int i = 0;i < n;i++) printf("%d%c", b[i]+1, " \n"[i==n-1]);
	return 0;
}