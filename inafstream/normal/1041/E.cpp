#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,cnt[1005],x,y,sz[1005],lst[1005];
vector<int> s1,s2;
int main()
{
	scanf("%d",&n);
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if (x!=n&&y!=n)
		{
			puts("NO");
			return 0;
		}
		if (x==y)
		{
			puts("NO");
			return 0;
		}
		sz[min(x,y)]++;
		lst[min(x,y)]=n;
	}
	for (i=n-1;i>=1;i--)
	{
		if (!sz[i])
		{
			for (j=i+1;j<=n;j++) if (sz[j]>1)
			{
				s1.push_back(lst[j]);
				s2.push_back(i);
				lst[j]=i;
				sz[j]--;
				break;
			}
			if (j>n)
			{
				puts("NO");
				return 0;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		if (sz[i]>1)
		{
			puts("NO");
			return 0;
		}
		if (sz[i]==1)
		{
			s1.push_back(lst[i]);
			s2.push_back(i);
		}
	}
	puts("YES");
	for (i=0;i<s1.size();i++) printf("%d %d\n",s1[i],s2[i]);
	return 0;
}