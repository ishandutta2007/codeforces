#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define SD(q) ((q)==b[b[q].fa].r)
using namespace std;
typedef long long LL;
const int N=400500,mo=998244353;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
struct SPYv
{
	int l,r,fa;
	int L,R,v;
	int mi,si;
	LL sum;
}b[N];
int root,b0;
void merge(int q)
{
	b[q].si=(b[q].R-b[q].L+1)+b[b[q].l].si+b[b[q].r].si;
	b[q].mi=min(b[q].v,min(b[b[q].l].mi,b[b[q].r].mi));
	b[q].sum=b[b[q].l].sum+b[b[q].r].sum+b[q].v*(b[q].R-b[q].L+1LL);
}
void rotate(int q)
{
	int w=b[q].fa;
	if(SD(q))
	{
		b[w].r=b[q].l;
		b[b[q].l].fa=w;
		b[q].l=w;
	}
	else 
	{
		b[w].l=b[q].r;
		b[b[q].r].fa=w;
		b[q].r=w;
	}
	if(SD(w))b[b[w].fa].r=q;
	else b[b[w].fa].l=q;
	b[q].fa=b[w].fa;b[w].fa=q;
	merge(w),merge(q);
}
void Splay(int q,int T)
{
	for(;b[q].fa!=T;)
	{
		if(b[b[q].fa].fa!=T)
		{
			if(SD(q)==SD(b[q].fa))rotate(b[q].fa);
			else rotate(q);
		}
		rotate(q);
	}
	if(!T)root=q;
}
int Sfind(int w)
{
	int q=root;
	for(;1;)
	{
		if(w>b[q].R)q=b[q].r;
		else if(w<b[q].L)q=b[q].l;
		else{
			if(w==b[q].R)return q;
			b[++b0].fa=q;
			b[b0].r=b[q].r;
			b[b[q].r].fa=b0;
			b[q].r=b0;

			b[b0].v=b[q].v;
			b[b0].R=b[q].R;
			b[b0].L=w+1;
			b[q].R=w;
			
			merge(b0),merge(q);
			return q;
		}
	}
}
int Sfindr(int w)
{
	int q=root;
	for(;1;)
	{
		if(w>b[q].R)q=b[q].r;
		else if(w<b[q].L)q=b[q].l;
		else{
			if(w==b[q].L)return q;
			b[++b0].fa=q;
			b[b0].r=b[q].r;
			b[b[q].r].fa=b0;
			b[q].r=b0;

			b[b0].v=b[q].v;
			b[b0].R=b[q].R;
			b[b0].L=w;
			b[q].R=w-1;
			
			merge(b0),merge(q);
			return b0;
		}
	}
}
int findmi(int v)
{
	int q=root;
	for(;1;)
	{
		if(b[b[q].l].mi<=v)q=b[q].l;
		else if(b[q].v<=v)return q;
		else q=b[q].r;
	}
}
int a[N];
int main()
{
	int q,w,e;
	b[0].mi=1e9;
	read(n),read(m);
	b0=n; 
	root=1;
	fo(i,1,n)
	{
		read(a[i]);
		b[i].v=a[i];
		b[i].fa=i-1;
		b[i].r=i+1;
		b[i].L=b[i].R=i;
	}
	b[n].r=0;
	fod(i,n,1)merge(i);

	fo(I,1,m)
	{
		// printf("%d              .....\n",I);
		int t;
		read(e),read(q),read(t);
		if(e==1)
		{
			Splay(Sfind(q),0);
			if(b[root].v>=t)continue;
			if(b[b[root].l].mi<=t)
			{
				Splay(findmi(t),root);
				b[root].L=b[b[root].l].L;

				b[b[b[root].l].l].fa=root;
				b[root].l=b[b[root].l].l;
			}
			b[root].v=t;
			merge(root);
		}else
		{
			Splay(Sfindr(q),0);
			ans=0;
			while(min(b[root].v,b[b[root].r].mi)<=t)
			{
				if(b[root].v>t)Splay(findmi(t),0);
				if(b[root].v*(b[root].R-b[root].L+1LL)>=t)
				{
					ans+=t/b[root].v;
					t%=b[root].v;
					continue;
				}
				ans+=b[root].R-b[root].L+1;
				t-=(b[root].R-b[root].L+1LL)*b[root].v;
				q=b[root].r;
				if(!q)break;
				for(;q;)
				{
					if(!b[q].l)
					{
						Splay(q,0);
						break;
					}
					if(b[b[q].l].sum<=t)
					{
						ans+=b[b[q].l].si;
						t-=b[b[q].l].sum;
						Splay(q,0);
						break;
					}
					q=b[q].l;
				}

			}
			printf("%d\n",ans);
		}
	}
	return 0;
}