#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,ans,mi;
int a[105],cnt[105];
vector<int> b;

int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[i]=cnt[i-1]+((a[i]%2==1)?1:-1);
	}
	
	for (i=1;i<n;i++) if (!cnt[i]) b.push_back(abs(a[i]-a[i+1]));
	
	sort(b.begin(),b.end());
	for (i=0;i<b.size();i++)
	{
		if (b[i]<=m)
		{
			m-=b[i];
			ans++;
		}
	}
	
	
	
	printf("%d\n",ans);
	
	return 0;
}