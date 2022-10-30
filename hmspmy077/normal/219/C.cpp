#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const int N=500005;

char s[N],ss[N],f[N];

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
		freopen("c.out","w",stdout);
	#endif
	int n,m;
	scanf("%d%d ",&n,&m);
	gets(s);
	s[n]='0';
	int ans=-1;
	for (char c='A';c<='A'+m-1;c++)
	{
		int tmp=0;
		if (s[0]!=c) tmp++;
		ss[0]=c;
		for (int i=1;i<n;i++)
			if (s[i]==ss[i-1])
			{
				tmp++;
				if (m==2)
				{
					if (ss[i-1]=='A') ss[i]='B';
					else ss[i]='A';
				}
				else
				{
					for (char cc='A';cc<='A'+m-1;cc++)
					{
						if (cc!=ss[i-1] && cc!=s[i+1])
						{
							ss[i]=cc;
							break;
						}
					}
				}
			}
			else ss[i]=s[i];
		if (ans==-1 || tmp<ans)
		{
			ans=tmp;
			for (int i=0;i<n;i++) f[i]=ss[i];
		}
	}
	printf("%d\n",ans);
	for (int i=0;i<n;i++) printf("%c",f[i]);
	printf("\n");
	return 0;
}