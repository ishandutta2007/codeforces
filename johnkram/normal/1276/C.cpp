#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
#define MAXM 1000005
#define ll long long
int n,m,i,j,x,y,a1,a2,r,c,ans[MAXN],b[MAXN];
map<int,int> s;
vector<int> a[MAXN];
int main()
{
	scanf("%d",&n);
	j=n;
	while(j--)
	{
		scanf("%d",&i);
		s[i]++;
	}
	for(auto t:s)a[t.second].push_back(t.first);
	for(i=1;i<=n;i++)b[i]=a[i].size();
	for(i=n;i;i--)b[i]+=b[i+1];
	for(i=1;i<=n;i++)
	{
		m+=b[i];
		j=m/i;
		if(j>=i&&j*i>a1)
		{
			a2=i;
			a1=j*i;
		}
	}
	printf("%d\n",a1);
	r=a2;
	c=a1/a2;
	printf("%d %d\n",r,c);
	for(i=n;i;i--)for(auto t:a[i])
	{
		if(!a1)break;
		for(j=0;j<i&&j<r;j++)
		{
			ans[x*c+y]=t;
			a1--;
			if(!a1)break;
			x++;
			if(x==r)x=0;
			do
			{
				y++;
				if(y==c)y=0;
			}while(ans[x*c+y]);
		}
	}
	for(i=0;i<r;i++,putchar('\n'))for(j=0;j<c;j++)printf("%d ",ans[i*c+j]);
	return 0;
}