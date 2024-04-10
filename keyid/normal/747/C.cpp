#include <bits/stdc++.h>
using namespace std;

const int MAXN=105,MAXT=1000005;

vector <int> c[MAXT];
bool off[MAXN];

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	fill(off+1,off+n+1,true);
	int head=1,now=n;
	while (q--)
	{
		int t,k,d;
		scanf("%d%d%d",&t,&k,&d);
		while (head<=t)
		{
			for (int j=0;j<c[head].size();j++)
				off[c[head][j]]=true;
			now+=c[head++].size();
		}
		if (now<k) puts("-1");
		else
		{
			now-=k;
			int s=0,cnt=0;
			for (int i=1;;i++)
				if (off[i])
				{
					off[i]=false;
					s+=i;
					if (t+d<=1000000)
						c[t+d].push_back(i);
					if (++cnt==k) break;
				}
			printf("%d\n",s);
		}
	}
	return 0;
}