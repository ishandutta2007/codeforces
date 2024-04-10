#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5,U=100;
bitset<N>can[U],a;int sg[N];
bool mark[N];
void init(int n,int f)
{
	rep(i,2,n)
	if(!mark[i])
	{
		a[i]=1;
		rep(j,2,n/i)
		{
			mark[i*j]=1;
			if(j<=i)a[i*j]=!mark[j];
		}
	}
	a[f]=0;
	
	rep(i,0,n)
	{
		sg[i]=0;
		while(can[sg[i]][i])++sg[i];
		can[sg[i]]|=a<<i;
	}
	int mx=0;
	rep(i,0,n)mx=max(mx,sg[i]);
	cerr<<mx<<endl;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n,f;
	cin>>n>>f;
	init(2e5,f);
	int ans=0;
	while(n--)
	{
		int l,m,r;
		scanf("%d%d%d",&l,&m,&r);
		ans^=sg[r-m-1]^sg[m-l-1];
	}
	if(ans)puts("Alice\nBob");
	else puts("Bob\nAlice");
}