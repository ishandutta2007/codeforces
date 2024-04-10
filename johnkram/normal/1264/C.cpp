#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define MAXN 262144
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
struct node
{
	int a,b;
	node(int x=0)
	{
		a=b=Pow(x,P-2);
	}
	node operator+(const node& y)
	{
		node t;
		t.a=(ll)a*y.a%P;
		t.b=((ll)b*y.a+y.b)%P;
		return t;
	}
}t[MAXN<<1];
set<int> s;
int n,q,i,j,k,a[MAXN],ans;
void build(int R,int l,int r)
{
	if(l==r)
	{
		t[R]=node(a[l]);
		return;
	}
	int mid=l+r>>1;
	build(R<<1,l,mid);
	build(R<<1|1,mid+1,r);
	t[R]=t[R<<1]+t[R<<1|1];
}
node ask(int R,int l,int r,int l1,int r1)
{
	if(l1==l&&r==r1)return t[R];
	int mid=l+r>>1;
	if(r1<=mid)return ask(R<<1,l,mid,l1,r1);
	if(l1>mid)return ask(R<<1|1,mid+1,r,l1,r1);
	return ask(R<<1,l,mid,l1,mid)+ask(R<<1|1,mid+1,r,mid+1,r1);
}
int main()
{
	scanf("%d%d",&n,&q);
	j=Pow(100,P-2);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i]=(ll)a[i]*j%P;
	}
	build(1,1,n);
	s.insert(1);
	s.insert(n+1);
	ans=ask(1,1,n,1,n).b;
	while(q--)
	{
		scanf("%d",&i);
		auto it=s.lower_bound(i);
		if(*it==i)
		{
			it++;
			j=*it;
			it--;
			it--;
			k=*it;
			s.erase(i);
			ans=((ll)ans+P-ask(1,1,n,k,i-1).b+P-ask(1,1,n,i,j-1).b+ask(1,1,n,k,j-1).b)%P;
		}
		else
		{
			j=*it;
			it--;
			k=*it;
			s.insert(i);
			ans=((ll)ans+ask(1,1,n,k,i-1).b+ask(1,1,n,i,j-1).b+P-ask(1,1,n,k,j-1).b)%P;
		}
		printf("%d\n",ans);
	}
	return 0;
}