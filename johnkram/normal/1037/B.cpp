#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll ans;
int n,m,i,j,x,y,a[MAXN],b[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		if(j<m)a[++x]=j;
		else if(j>m)b[++y]=j;
	}
	sort(a+1,a+x+1);
	sort(b+1,b+y+1,greater<int>());
	for(i=n/2+1;i<=x;i++)ans+=m-a[i];
	for(i=n/2+1;i<=y;i++)ans+=b[i]-m;
	cout<<ans<<endl;
	return 0;
}