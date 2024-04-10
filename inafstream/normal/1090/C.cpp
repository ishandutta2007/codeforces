#include <bits/stdc++.h>
using namespace std;
int n,m;
int vis[100005],fr[100005],to[100005];
vector<int> seq[100005];
struct f{int id,sz;}a[100005];
bool cmp(f x,f y){return x.sz>y.sz;}
void move(int x,int y,int z)
{
	int i,j;
	vector<int> tmp;
	for (i=0;i<seq[y].size();i++) vis[seq[y][i]]=1;
	while (z)
	{
		int t=seq[x].back();
		seq[x].pop_back();
		if (vis[t]) {tmp.push_back(t);continue;}
		printf("%d %d %d\n",x,y,t);
		seq[y].push_back(t);z--;
	}
	for (i=0;i<seq[y].size();i++) vis[seq[y][i]]=0;
	while (!tmp.empty()){seq[x].push_back(tmp.back());tmp.pop_back();}
}
int main()
{
	int i,j,_;
	scanf("%d%d",&n,&_);
	for (i=1;i<=n;i++)
	{
		a[i].id=i;
		scanf("%d",&a[i].sz);m+=(fr[i]=a[i].sz);
		for (j=1;j<=a[i].sz;j++)
		{
			int x;
			scanf("%d",&x);
			seq[i].push_back(x);
		}
	}
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++) to[i]=m/n+((m%n)>=i);
	int ans=0;
	for (i=1;i<=n;i++)
	{
		ans+=max(0,to[i]-fr[a[i].id]);
	}
	printf("%d\n",ans);
	for (i=1,j=n;i<j;)
	{
		int x=a[i].id,y=a[j].id;
		if (fr[x]==to[i]) {i++;continue;}
		if (fr[y]==to[j]) {j--;continue;}
		int s=min(abs(fr[x]-to[i]),abs(fr[y]-to[j]));
		fr[x]-=s;fr[y]+=s;
		move(x,y,s);
	}
	return 0;
}