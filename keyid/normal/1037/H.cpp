#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005,MAXM=200005,SIGMA=26;

struct query
{
	int l,r,len,id,pf;
};

struct ret
{
	int st,len;
}ans[MAXM];

int n,t[MAXN],t2[MAXN],c[MAXN],sa[MAXN],rnk[MAXN],maxbit,st[20][MAXN],yl,yr,V,minv[MAXN*4];
char s[MAXN],s2[MAXM];
vector <query> q[MAXN];

void build_sa(int l,int m)
{
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
		for (int i=0;i<m;i++)
			c[i]=0;
		for (int i=0;i<l;i++)
			c[x[i]]++;
		for (int i=1;i<m;i++)
			c[i]+=c[i-1];
		for (int i=l-1;i>=0;i--)
			sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for (int i=1;i<l;i++)
			x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
		if (p>=l)
			break;
		m=p;
	}
}

void getheight(int l,int *hei)
{
	for (int i=1;i<=l;i++)
		rnk[sa[i]]=i;
	for (int i=0,k=0,j;i<l;i++)
	{
		if (k)
			k--;
		j=sa[rnk[i]-1];
		while (s[i+k]==s[j+k]) k++;
		hei[rnk[i]]=k;
	}
}

int RMQ(int l,int r)
{
	int k=31-__builtin_clz(r-l+1);
	return min(st[k][l],st[k][r-(1<<k)+1]);
}

int LCP(int l,int r)
{
	if (l==r)
		return n-sa[l];
	if (l>r)
		swap(l,r);
	return RMQ(l+1,r);
}

void get_lcp(int &now,int &nowp)
{
	int l=1,r=n,len=strlen(s2);
	now=nowp=0;
	while (l<=r)
	{
		int m=l+r>>1;
		int lcp=LCP(m,now);
		if (lcp<nowp)
		{
			if (m<now)
				l=m+1;
			else
				r=m-1;
		}
		else
		{
			while (nowp<len&&s[sa[m]+nowp]==s2[nowp]) nowp++;
			now=m;
			if (nowp==len)
				return;
			if (s[sa[m]+nowp]<s2[nowp])
				l=m+1;
			else
				r=m-1;
		}
	}
}

void get_pos(int &p,int &len)
{
	assert(p!=0);
	int l=1,r=p;
	while (l<=r)
	{
		int m=l+r>>1;
		if (LCP(m,p)>=len)
			r=m-1;
		else
			l=m+1;
	}
	p=l;
	r=n;
	while (l<=r)
	{
		int m=l+r>>1;
		if (LCP(m,p)>=len&&s[sa[m]+len]<s2[len])
			l=m+1;
		else
			r=m-1;
	}
	if (l>n)
	{
		p=l;
		return;
	}
	len=min(len,LCP(l,p));
	p=l;
}

void get_nxt(int &pos,int &pfix)
{
	pos++;
	for (int i=maxbit;i>=0;i--)
		if (pos+(1<<i)-1<=n&&st[i][pos]>=pfix)
			pos+=1<<i;
	pfix=st[0][pos];
}

void build(int o,int l,int r)
{
	minv[o]=INT_MAX;
	if (l<r)
	{
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
}

void update(int o,int l,int r)
{
	minv[o]=V;
	if (l<r)
	{
		int m=l+r>>1;
		if (yl<=m)
			update(o<<1,l,m);
		else
			update(o<<1|1,m+1,r);
	}
}

void get_ans(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		V=min(V,minv[o]);
	else
	{
		int m=l+r>>1;
		if (yl<=m)
			get_ans(o<<1,l,m);
		if (yr>m)
			get_ans(o<<1|1,m+1,r);
	}
}

int main()
{
	//freopen("read.txt","r",stdin);
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)
		s[i]-='a'-1;
	s[n]=0;
	build_sa(n+1,27);
	getheight(n,st[0]);
	for (int i=0;i<=n;i++)
		s[i]+='a'-1;
	while ((1<<maxbit)<=n) maxbit++;
	maxbit--;
	for (int j=1;j<=maxbit;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[j][i]=min(st[j-1][i],st[j-1][i+(1<<j-1)]);
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d%d%s",&l,&r,s2);
		l--;
		r--;
		int pfix,pos;
		get_lcp(pos,pfix);
		get_pos(pos,pfix);
		for (int k=pos,j=pfix;k<=n;)
		{
			if (r-j>=l)
				q[k].push_back({l,r-j,j+1,i,pos});
			get_nxt(k,j);
		}
	}
	for (int i=0;i<m;i++)
		ans[i].st=-1;
	build(1,0,n-1);
	for (int i=n;i>=1;i--)
	{
		yl=sa[i];
		V=i;
		update(1,0,n-1);
		for (auto &qu:q[i])
		{
			yl=qu.l;
			yr=qu.r;
			V=INT_MAX;
			get_ans(1,0,n-1);
			if (V<=n&&LCP(V,qu.pf)>=qu.len-1)
				ans[qu.id]={sa[V],qu.len};
		}
	}
	for (int i=0;i<m;i++)
	{
		if (ans[i].st!=-1)
		{
			for (int j=ans[i].st;j<ans[i].st+ans[i].len;j++)
				putchar(s[j]);
			puts("");
		}
		else
			puts("-1");
	}
	return 0;
}