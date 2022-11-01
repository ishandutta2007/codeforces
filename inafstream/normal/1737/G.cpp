#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,d,q,c;

namespace treap
{
	int rt,rnd[100005],cnt;
	int sz[100005],ch[100005][2];
	long long num[100005],tag[100005];
	int gen(long long x)
	{
		cnt++;rnd[cnt]=rand();
		num[cnt]=x;tag[cnt]=0;
		sz[cnt]=1;
		return cnt;
	}
	void pushdown(int x)
	{
		if(tag[x]==0) return;
		if(ch[x][0]) num[ch[x][0]]+=tag[x],tag[ch[x][0]]+=tag[x];
		if(ch[x][1]) num[ch[x][1]]+=tag[x],tag[ch[x][1]]+=tag[x];
		tag[x]=0;
	}
	void split(int x,long long k,int &l,int &r)
	{
		if(!x){l=r=0;return;}
		pushdown(x);
		if(num[x]<=k)
		{
			split(ch[x][1],k,ch[x][1],r);
			l=x;
			sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
			return;
		}
		else
		{
			split(ch[x][0],k,l,ch[x][0]);
			r=x;
			sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
			return;
		}
	}
	void splitl(int x,int k,int &l,int &r)
	{
		if(!x){l=r=0;return;}
		pushdown(x);
		if(sz[ch[x][0]]+1<=k)
		{
			splitl(ch[x][1],k-sz[ch[x][0]]-1,ch[x][1],r);
			l=x;
			sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
			return;
		}
		else
		{
			splitl(ch[x][0],k,l,ch[x][0]);
			r=x;
			sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
			return;
		}
	}
	int merge(int x,int y)
	{
		if(!x||!y) return x+y;
		pushdown(x);
		pushdown(y);
		if(rnd[x]>rnd[y])
		{
			ch[x][1]=merge(ch[x][1],y);
			sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
			return x;
		}
		else
		{
			ch[y][0]=merge(x,ch[y][0]);
			sz[y]=sz[ch[y][0]]+sz[ch[y][1]]+1;
			return y;
		}
	}
	void insert(long long v)
	{
		int x=gen(v);
		int l,r;
		split(rt,v,l,r);
		r=merge(x,r);
		rt=merge(l,r);
	}
	void opt(int k)
	{
		assert(sz[rt]==c);
		int dlt=(d+sz[rt]-1);
		num[rt]+=1ll*k/sz[rt]*dlt;
		tag[rt]+=1ll*k/sz[rt]*dlt;
		int c=k%sz[rt];
		if(c)
		{
			int l,r;
			splitl(rt,c,l,r);
			num[l]+=dlt;
			tag[l]+=dlt;
			rt=merge(r,l);
		}
	}
	int query(int x,long long k)
	{
		if(!x) return 0;
		pushdown(x);
		if(num[x]<=k) return sz[ch[x][0]]+1+query(ch[x][1],k);
		return query(ch[x][0],k);
	}
	long long first(int x)
	{
		while(ch[x][0])
		{
			pushdown(x);
			x=ch[x][0];
		}
		return num[x];
	}

	void print(int x)
	{
		if(!x) return;
		pushdown(x);
		if(ch[x][0]) print(ch[x][0]);
		printf("%lld ",num[x]);
		if(ch[x][1]) print(ch[x][1]);
	}
};

int a[100005],b[100005];
char s[100005];

int qk[100005],qm[100005];
long long ans[100005];

int ord[100005],p;

int copt;
vector<int> v;

void query(int i)
{
	long long l=1,r=1.1e18+1,mid,res=0;
	while(l<r)
	{
		mid=(l+r)/2;
		int cnt=0;
		int p=upper_bound(b+1,b+n+1,min(1ll*b[n]+1,mid))-b-1;
		cnt+=p;
		cnt-=upper_bound(v.begin(),v.end(),min(1ll*b[n]+1,mid))-v.begin();
		cnt+=treap::query(treap::rt,mid-p);
		if(cnt<qm[i]) l=mid+1,res=mid;
		else r=mid;
	}
	ans[i]=res+1;
}

void tryopt(int k)
{
	while(p<=q&&copt+k>=qk[ord[p]])
	{
		treap::opt(qk[ord[p]]-copt);
		k-=qk[ord[p]]-copt;
		copt+=qk[ord[p]]-copt;
		query(ord[p++]);
	}
	while(k)
	{
		treap::opt(k);copt+=k;
		return;
	}
}

void solve()
{
	scanf("%d%d%d",&n,&d,&q);
	rep(i,n)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		a[i]-=i;
	}
	scanf("\n");
	rep(i,n) scanf("%c",&s[i]);

	rep(i,q)
	{
		scanf("%d%d",&qk[i],&qm[i]);
		ord[i]=i;
	}

	sort(ord+1,ord+q+1,[&](const int &x,const int &y){return qk[x]<qk[y];});
	p=1;

	rep(i,n) if(s[i]=='1')
	{
		if(!treap::rt);
		else
		{
			long long f=treap::first(treap::rt);
			long long t=(a[i]-f)/(d+c-1);
			tryopt(t*c);
			int rem=treap::query(treap::rt,a[i]);
			tryopt(rem);
		}
		treap::insert(a[i]);c++;v.push_back(b[i]);
		assert(treap::first(treap::rt)==a[i]);

//		treap::print(treap::rt);puts("");
	}
	if(p<=q) tryopt(qk[ord[q]]-copt+1);
	assert(p>q);

	rep(i,q) printf("%lld\n",ans[i]);
}

int main()
{
	solve();
	return 0;
}