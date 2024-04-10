#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e5+5;
vector<int>lk[N];
int n,m,k,du[N],ex[N],ey[N],ans,ans_[N];

void del(int x)
{
	if(--du[x]==k-1)
	{
		--ans;
		for(auto y:lk[x])del(y);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n>>m>>k;
	rep(i,1,m)
	{
		scanf("%d%d",ex+i,ey+i);
		int x=ex[i],y=ey[i];
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	vector<int>q;
	rep(i,1,n)	
	if((du[i]=lk[i].size())>=k)++ans;
	else q.push_back(i);
	for(auto i:q)
	for(auto j:lk[i])del(j);
	per(i,m,1)
	{
		ans_[i]=ans;
		if(du[ex[i]]>=k){lk[ex[i]].pop_back();del(ey[i]);}
		if(du[ey[i]]>=k){lk[ey[i]].pop_back();del(ex[i]);}
	}
	rep(i,1,m)printf("%d\n",ans_[i]);
}