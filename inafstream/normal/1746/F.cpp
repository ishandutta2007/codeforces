#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

mt19937 Rand(256);

// typedef unsigned long long u64;

// const u64 INF=6e13;

int rd()
{
	return Rand()%2;
}
 

int n;

struct bit
{
	int a[300005][65];
	void add(int x,int *c)
	{
		while(x<=n)
		{
			rep(i,60) a[x][i]+=c[i];
			x+=(x&-x);
		}
	}
	void add(int x,int *c,int *d)
	{
		while(x<=n)
		{
			rep(i,60) a[x][i]+=c[i]-d[i];
			x+=(x&-x);
		}
	}
	void query(int x,int *c)
	{
		while(x)
		{
			rep(i,60) c[i]+=a[x][i];
			x&=(x-1);
		}
	}
}T;

int m;
int a[300005];

int op[300005];
int pos[300005],to[300005];
int ql[300005],qr[300005],qk[300005];
int ans[300005];

int c[65];
int rnd[600005][65];


vector<int> v;

void solve()
{
	scanf("%d%d",&n,&m);
	
	rep(i,n) scanf("%d",&a[i]),v.push_back(a[i]);
	rep(i,m)
	{
		scanf("%d",&op[i]);
		if(op[i]==1)
		{
			scanf("%d%d",&pos[i],&to[i]);
			v.push_back(to[i]);
		}
		else
		{
			scanf("%d%d%d",&ql[i],&qr[i],&qk[i]);
			if((qr[i]-ql[i]+1)%qk[i]==0) ans[i]=1;
		}
	}
 
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
 
	rep(i,n) a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	rep(i,m) if(op[i]==1)
	{
		to[i]=lower_bound(v.begin(),v.end(),to[i])-v.begin()+1;
	}

	rep(i,n) T.add(i,rnd[a[i]]);
	int _=0;
	rep(i,m)
	{
		if(op[i]==1)
		{
			T.add(pos[i],rnd[to[i]],rnd[a[pos[i]]]);
			a[pos[i]]=to[i];
		}
		else
		{
			if(ans[i])
			{
				rep(j,60) c[j]=0;
				T.query(ql[i]-1,c);
				rep(j,60) c[j]*=-1;
				T.query(qr[i],c);
				rep(j,60) if(c[j]%qk[i]!=0) ans[i]=0;
			}
			if(ans[i]) puts("YES");else puts("NO");
		}
	}
}


int main()
{
	rep(i,600000)rep(j,60) rnd[i][j]=rd();
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}