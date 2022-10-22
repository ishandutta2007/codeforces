#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
struct Que
{
	int a,b;
	int id;
	inline void read(int i)
	{
		cin>>a>>b;
		id=i;
		return;
	}
	bool operator<(const Que &oth) const
	{
		if(a==oth.a)
			return id<oth.id;
		return a>oth.a;
	}
};
int p[300010];
int br[300010];
int tree[1100010];
int odp[300010];
Que que[300010];
pair<int,int> xd[300010];
int pot;
inline void add(int x)
{
	for(x+=pot-1;x>0;x/=2)
		tree[x]++;
	return;
}
inline int read(int l,int r)
{
	int ans=0;
	for(l+=pot-1,r+=pot-1;l<=r;l/=2,r/=2)
	{
		if(l%2==1)
		{
			ans+=tree[l];
			l++;
		}
		if(r%2==0)
		{
			ans+=tree[r];
			r--;
		}
	}
	return ans;
}
inline int fnd(int x)
{
	int i=1;
	for(;i<pot;)
	{
		if(tree[2*i+1]>=x)
			i=2*i+1;
		else
		{
			x-=tree[2*i+1];
			i=2*i;
		}
	}
	return i-pot;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,a,i,j;
	cin>>n>>q;
	for(pot=1;pot<=n;pot*=2);
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a>i)
			p[i]=n+1;
		else
			p[i]=i-a;
		if(p[i]==n+1)
			br[i]=0;
		else if(p[i]==0)
			br[i]=i;
		else
			br[i]=fnd(p[i]);
		add(br[i]+1);
		xd[i]={-br[i],i};
		//cerr<<i<<" "<<p[i]<<" "<<br[i]<<"\n";
	}
	for(i=1;i<=q;i++)
		que[i].read(i);
	sort(que+1,que+q+1);
	sort(xd+1,xd+n+1);
	for(i=1;i<2*pot;i++)
		tree[i]=0;
	for(i=1,j=1;i<=q;i++)
	{
		while((j<=n)&&(-xd[j].fi>que[i].a))
		{
			add(xd[j].se);
			j++;
		}
		odp[que[i].id]=read(que[i].a+1,n-que[i].b);
	}
	for(i=1;i<=q;i++)
		cout<<odp[i]<<"\n";
	return 0;
}