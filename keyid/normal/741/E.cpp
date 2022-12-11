#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXL=200005,MAXQ=100005;

struct query
{
	int l,r,x,y,id;
};

struct query2
{
	int l,id;
};

char s[MAXL];
int t[MAXL],t2[MAXL],c[MAXL],sa[MAXL],rnk[MAXL],height[MAXL],delta[MAXL],maxbit,d[20][MAXL],id[MAXL/2],rk[MAXL/2],_min[20][MAXL/2],ans[MAXQ],minv[MAXL/2],p[MAXL/2];
vector <query> qu[400];
vector <query2> qu2[MAXL/2];

void build_sa(int l,int m)
{
	int *x=t,*y=t2;
	for (int i=0;i<l;i++)
		c[x[i]=s[i]]++;
	for (int i=1;i<m;i++) c[i]+=c[i-1];
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
		p=1;x[sa[0]]=0;
		for (int i=1;i<l;i++)
			x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		if (p>=l) break;
		m=p;
	}
}

void getheight(int l)
{
	for (int i=1;i<=l;i++)
		rnk[sa[i]]=i;
	for (int i=0,k=0,j;i<l;i++) 
	{
		if (k) k--;
		j=sa[rnk[i]-1];
		while (s[i+k]==s[j+k]) k++;
		height[rnk[i]]=k;
	}
}

void RMQ_init(int l)
{
	while ((1<<maxbit)<=l) maxbit++;
	maxbit--;
	delta[1]=0;
	for (int i=2;i<=l;i++) delta[i]=delta[i>>1]+1;
	for (int i=1;i<=l;i++) d[0][i]=height[i];
	for (int j=1;j<=maxbit;j++)
		for (int i=1;i+(1<<j)-1<=l;i++)
			d[j][i]=min(d[j-1][i],d[j-1][i+(1<<j-1)]);
}

int RMQ(int l,int r)
{
	int k=delta[r-l+1];
	return min(d[k][l],d[k][r-(1<<k)+1]);
}

int LCP(int x,int y)
{
	//if (x==y) return l-x;
	x=rnk[x];y=rnk[y];
	if (x>y) swap(x,y);
	return RMQ(x+1,y);
}

int l,l2;

int check(int p1,int p2,int l)
{
	int lcp=LCP(p1,p2);
	if (lcp>=l) return 0;
	return s[p1+lcp]<s[p2+lcp]?-1:1;
}

bool cmp(int p1,int p2)
{
	bool flag=false;
	if (p1>p2)
	{
		swap(p1,p2);
		flag=true;
	}
	int f;
	if (l2-l<p2-p1)
	{
		f=check(l,p1,l2-l);
		if (f) return (f<0)^flag;
		f=check(p1,p1+l2-l,p2-(p1+l2-l));
		if (f) return (f<0)^flag;
		f=check(p2-(l2-l),l,l2-l);
		if (f) return (f<0)^flag;
	}
	else if (l2-l>p2-p1)
	{
		f=check(l,p1,p2-p1);
		if (f) return (f<0)^flag;
		f=check(l+p2-p1,l,l2-(l+p2-p1));
		if (f) return (f<0)^flag;
		f=check(p1,l2-(p2-p1),p2-p1);
		if (f) return (f<0)^flag;
	}
	else
	{
		f=check(l,p1,l2-l);
		if (f) return (f<0)^flag;
	}
	return (p1<p2)^flag;
}

int Min(int a,int b)
{
	if (a==-1) return b;
	return rk[a]<rk[b]?a:b;
}

int query_min(int l,int r)
{
	int k=delta[r-l+1];
	return Min(_min[k][l],_min[k][r-(1<<k)+1]);
}

int find(int x)
{
	if (p[x]==x) return x;
	int f=find(p[x]);
	minv[x]=Min(minv[x],minv[p[x]]);
	return p[x]=f;
}

int main()
{
	scanf("%s",s);
	l=strlen(s);
	scanf("%s",s+l);
	l2=strlen(s);
	for (int i=0;i<l2;i++)
		s[i]-='a'-1;
	//00
	build_sa(l2+1,27);
	getheight(l2);
	RMQ_init(l2);
	for (int i=0;i<=l;i++)
		id[i]=i;
	sort(id,id+l+1,cmp);
	for (int i=0;i<=l;i++)
		rk[id[i]]=i;
	for (int i=0;i<=l;i++)
		_min[0][i]=i;
	maxbit=0;
	while ((1<<maxbit)<=l+1) maxbit++;
	maxbit--;
	for (int j=1;j<=maxbit;j++)
		for (int i=0;i+(1<<j)-1<=l;i++)
			_min[j][i]=Min(_min[j-1][i],_min[j-1][i+(1<<j-1)]);
	int q;
	scanf("%d",&q);
	int bs=round(sqrt(l));
	fill(ans,ans+q,-1);
	for (int i=0;i<q;i++)
	{
		int ll,rr,k,x,y;
		scanf("%d%d%d%d%d",&ll,&rr,&k,&x,&y);
		if (k>bs)
			for (int j=0;j<=l;j+=k)
			{
				int tl=max(j+x,ll),tr=min(j+y,rr);
				if (tl<=tr)
					ans[i]=Min(ans[i],query_min(tl,tr));
			}
		else
			qu[k].pb((query){ll,rr,x,y,i});
	}
	for (int i=1;i<=bs;i++)
	{
		for (int j=0;j<=l;j++)
			qu2[j].clear();
		for (int j=0;j<qu[i].size();j++)
			for (int k=qu[i][j].x;k<=qu[i][j].y;k++)
			{
				int tl=qu[i][j].l/i*i+k,tr=qu[i][j].r/i*i+k;
				if (tl<qu[i][j].l)
					tl+=i;
				if (tl-i>=qu[i][j].l)
					tl-=i;
				if (tr>qu[i][j].r)
					tr-=i;
				if (tl<=tr)
					qu2[tr].pb({tl,qu[i][j].id});
			}
		for (int j=0;j<=l;j++)
			minv[j]=p[j]=j;
		for (int j=0;j<=l;j++)
		{
			for (int k=0;k<qu2[j].size();k++)
			{
				find(qu2[j][k].l);
				ans[qu2[j][k].id]=Min(ans[qu2[j][k].id],minv[qu2[j][k].l]);
			}
			p[j]=j+i;
		}
	}
	for (int i=0;i<q;i++)
		printf("%d ",ans[i]);
	return 0;
}