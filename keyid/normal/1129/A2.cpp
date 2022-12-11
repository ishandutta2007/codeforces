#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=20005;

vector <int> s[MAXN];
int mn[MAXN];

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		s[a-1].pb(b-1);
	}
	memset(mn,0x3f,sizeof(mn));
	for (int i=0;i<n;i++)
		for (int x:s[i])
			mn[i]=min(mn[i],(x>=i?x:x+n)-i);
	for (int i=0;i<n;i++)
	{
		int ans=0;
		for (int j=0;j<n;j++)
			if (!s[j].empty())
				ans=max(ans,((int)s[j].size()-1)*n+(j>=i?j:j+n)-i+mn[j]);
		printf("%d ",ans);
	}
	return 0;
}