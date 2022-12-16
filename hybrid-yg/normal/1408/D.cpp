#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,i,t,k,ans=1000000000,j,mx;
struct str{
	int x,y;
}a[N],b[N];
vector<int> w[1000005];
bool cmp(str a,str b)
{
	return a.x<b.x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d %d",&a[i].x,&a[i].y);
	for(i=1;i<=m;++i)
		scanf("%d %d",&b[i].x,&b[i].y);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a[i].x<=b[j].x&&a[i].y<=b[j].y)
				w[b[j].x-a[i].x+1].push_back(b[j].y-a[i].y+1);
	for(i=1000001;i>=0;--i)
	{
		ans=min(ans,mx+i);
		for(auto it:w[i])
			mx=max(mx,it);
	}
	cout<<ans;
}