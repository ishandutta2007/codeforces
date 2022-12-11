#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

int p[MAXN];
char str[MAXN];

int main()
{
	int n,k,cnt=0;
	scanf("%d%d%s",&n,&k,str);
	for (int i=0;i<n;i++)
		if (str[i]=='0')
			p[cnt++]=i;
	int pos=0,ans=INT_MAX;
	for (int i=k;i<cnt;i++)
	{
		int p1=p[i-k],p2=p[i];
		while (p[pos]-p1<p2-p[pos])
		{
			ans=min(ans,max(p[pos]-p1,p2-p[pos]));
			pos++;
		}
		ans=min(ans,max(p[pos]-p1,p2-p[pos]));
	}
	printf("%d",ans);
	return 0;
}