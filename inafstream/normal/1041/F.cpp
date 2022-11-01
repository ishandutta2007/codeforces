#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,c,ans,xiahuren,a[100005],b[100005];
map<int,int> cnt;
int main()
{
	scanf("%d%d",&n,&xiahuren);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d%d",&m,&xiahuren);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	for (c=1;c<=1000000000;c*=2)
	{
		cnt.clear();
		for (i=1;i<=n;i++)
		{
			cnt[a[i]%(c*2)]++;
		}
		for (i=1;i<=m;i++)
		{
			cnt[(b[i]%(c*2)+c)%(c*2)]++;
		}
		for (map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++) ans=max(ans,it->second);
	}
	cnt.clear();
	for (i=1;i<=n;i++)
	{
		cnt[a[i]]++;
	}
	for (i=1;i<=m;i++)
	{
		cnt[b[i]]++;
	}
	for (map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++) ans=max(ans,it->second);
	cout<<ans<<endl;
	return 0;
}