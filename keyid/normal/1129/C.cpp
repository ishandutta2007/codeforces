#include <bits/stdc++.h>
using namespace std;

const int MOD=1000000007,MAXM=3005;
const char fb[4][5]={"0011","0101","1110","1111"};

int sz,ch[MAXM*MAXM][2],fa[MAXM*MAXM],f[MAXM*MAXM];
char s[MAXM],p[MAXM*MAXM];

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int m,ans=0;
	scanf("%d",&m);
	f[0]=1;
	for (int i=0;i<m;i++)
	{
		scanf("%s",s+i);
		int u=0;
		for (int j=i;j>=0;j--)
		{
			int c=s[j]-'0';
			if (!ch[u][c])
			{
				ch[u][c]=++sz;
				fa[sz]=u;
				p[sz]=s[j];
				bool flag=true;
				int now=fa[sz];
				for (int j=0;j<3;j++,now=fa[now])
				{
					f[sz]=(f[sz]+f[now])%MOD;
					if (now==0)
					{
						flag=false;
						break;
					}
				}
				for (int j=0;j<4&&flag;j++)
				{
					bool ok=false;
					for (int k=sz,y=0;y<4;y++,k=fa[k])
						if (p[k]!=fb[j][y])
						{
							ok=true;
							break;
						}
					if (!ok)
						flag=false;
				}
				if (flag)
					f[sz]=(f[sz]+f[now])%MOD;
				ans=(ans+f[sz])%MOD;
			}
			u=ch[u][c];
		}
		printf("%d\n",ans);
	}
	return 0;
}