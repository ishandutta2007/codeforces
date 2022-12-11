#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=500005;

char s[MAXN];
int n,sa[MAXN],rnk[MAXN],maxbit,st[20][MAXN],dp[MAXN],yl,yr,V,mxv[MAXN*4];

void build_sa(int l,int m)
{
	static int t[MAXN],t2[MAXN],c[MAXN];
	int *x=t,*y=t2;
	for (int i=0;i<m;i++)
		c[i]=0;
	for (int i=0;i<l;i++)
		c[x[i]=s[i]]++;
	for (int i=1;i<m;i++)
		c[i]+=c[i-1];
	for (int i=l-1;i>=0;i--)
		sa[--c[x[i]]]=i;
	for (int k=1;k<l;k<<=1)
	{
		int p=0;
		for (int i=l-k;i<l;i++) y[p++]=i;
		for (int i=0;i<l;i++) if (sa[i]>=k) y[p++]=sa[i]-k;
		for (int i=0;i<m;i++) c[i]=0;
		for (int i=0;i<l;i++) c[x[i]]++;
		for (int i=1;i<m;i++) c[i]+=c[i-1];
		for (int i=l-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for (int i=1;i<l;i++)
			x[sa[i]]= y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		if (p>=l)
			break;
		m=p;
	}
}

void get_height(int l)
{
	for (int i=1;i<=l;i++)
		rnk[sa[i]]=i;
	for (int i=0,k=0;i<l;i++)
	{
		if (k) k--;
		int j=sa[rnk[i]-1];
		while (s[i+k]==s[j+k]) k++;
		st[0][rnk[i]]=k;
	}
}

int LCP(int a,int b)
{
	if (a>b)
		swap(a,b);
	a++;
	int k=31-__builtin_clz(b-a+1);
	return min(st[k][a],st[k][b-(1<<k)+1]);
}

void update(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (yl<=m)	update(lc,l,m);
		else update(rc,m+1,r);
		mxv[o]=max(mxv[lc],mxv[rc]);
	}
	else
		mxv[o]=V;
}

void query(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		V=max(V,mxv[o]);
	else
	{
		int m=l+r>>1;
		if (yl<=m) query(o<<1,l,m);
		if (yr>m) query(o<<1|1,m+1,r);
	}
}

bool check2(int x,int pos)
{
	int p=rnk[pos];
	int l=1,r=p-1;
	while (l<=r)
	{
		int m=l+r>>1;
		if (LCP(m,p)<x)
			l=m+1;
		else
			r=m-1;
	}
	yl=l;
	l=p+1;
	r=n;
	while (l<=r)
	{
		int m=l+r>>1;
		if (LCP(m,p)<x)
			r=m-1;
		else
			l=m+1;
	}
	yr=r;
	V=0;
	query(1,1,n);
	return V>=x;
}

bool check(int x,int p)
{
	if (x==1)
		return true;
	return check2(x-1,p)||check2(x-1,p+1);
}

void add(int p)
{
	yl=rnk[p];
	V=dp[p];
	update(1,1,n);
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	scanf("%d%s",&n,s);
	for (int i=0;i<n;i++)
		s[i]-='a'-1;
	build_sa(n+1,27);
	get_height(n);
	while ((1<<maxbit)<=n) maxbit++;
	maxbit--;
	for (int j=1;j<=maxbit;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[j][i]=min(st[j-1][i],st[j-1][i+(1<<j-1)]);
	int ans=0;
	for (int i=n-1;i>=0;i--)
	{
		int &ret=dp[i];
		ret=dp[i+1]+1;
		while (!check(ret,i))
			add(--ret+i);
		ans=max(ans,ret);
	}
	printf("%d",ans);
	return 0;
}