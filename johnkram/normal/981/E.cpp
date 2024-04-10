#include<bits/stdc++.h>
using namespace std;
vector<int> t[40005];
bitset<10001> ans,o;
int n,m,i,j,k;
void fix(int R,int l,int r,int l1,int r1,int d)
{
	if(l1<=l&&r<=r1)
	{
		t[R].push_back(d);
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(R<<1,l,mid,l1,r1,d);
	if(r1>mid)fix(R<<1|1,mid+1,r,l1,r1,d);
}
void work(int R,int l,int r,bitset<10001> o)
{
	m=t[R].size();
	for(i=0;i<m;i++)o|=o<<t[R][i];
	if(l==r)
	{
		ans|=o;
		return;
	}
	int mid=l+r>>1;
	work(R<<1,l,mid,o);
	work(R<<1|1,mid+1,r,o);
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		fix(1,1,n,i,j,k);
	}
	o[0]=1;
	work(1,1,n,o);
	for(m=0,i=1;i<=n;i++)m+=ans[i];
	printf("%d\n",m);
	for(i=1;i<=n;i++)if(ans[i])printf("%d ",i);
	return 0;
}