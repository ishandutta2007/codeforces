#include <bits/stdc++.h>
using namespace std;

const int MAXN=300005;

int ans;
queue <int> q[MAXN];
set <int> s;

int main()
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for (int ty,x,now=1;Q--;)
	{
		scanf("%d%d",&ty,&x);
		if (ty==1)
		{
			ans++;
			q[x].push(now);
			s.insert(now++);
		}
		else if (ty==2)
		{
			while (!q[x].empty())
			{
				if (s.find(q[x].front())!=s.end())
				{
					s.erase(q[x].front());
					ans--;
				}
				q[x].pop();
			}
		}
		else
		{
			while (!s.empty()&&*s.begin()<=x)
			{
				s.erase(s.begin());
				ans--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}