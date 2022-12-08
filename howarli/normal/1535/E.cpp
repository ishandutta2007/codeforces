#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define SD(q) ((q)==tr[tr[q].fa].r)
using namespace std;
typedef long long LL;
const int N=300500;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
int n,m;

struct SPY
{
	int l,r,fa;
	int mi;
	LL c,v;
}tr[N];

vector<int>B[N];

void merge(int q)
{
	tr[q].mi=q;
	if(tr[tr[tr[q].l].mi].c<tr[tr[q].mi].c)tr[q].mi=tr[tr[q].l].mi;
	if(tr[tr[tr[q].r].mi].c<tr[tr[q].mi].c)tr[q].mi=tr[tr[q].r].mi;
}
void rotate(int q)
{
	int w=tr[q].fa;
	if(!SD(q))
	{
		tr[w].l=tr[q].r;
		tr[tr[q].r].fa=w;
		tr[q].r=w;
	}else
	{
		tr[w].r=tr[q].l;
		tr[tr[q].l].fa=w;
		tr[q].l=w;
	}
	if(SD(w))tr[tr[w].fa].r=q;
	else tr[tr[w].fa].l=q;
	tr[q].fa=tr[w].fa;
	tr[w].fa=q;
	merge(w);
	merge(q);
}
void Splay(int q,int T=0)
{
	while(tr[q].fa!=T)
	{
		if(tr[tr[q].fa].fa!=T)
		{
			if(SD(q)==SD(tr[q].fa))rotate(tr[q].fa);
			else rotate(q);
		}
		rotate(q);
	}
}

int main()
{
	int q,w,e;
	read(n),read(q),read(w);
	tr[0].c=1e9;

	tr[1].v=q;
	tr[1].c=w;
	tr[1].mi=1;

	fo(I,2,n+1)
	{
		read(q);
		if(q==1)
		{
			read(q),read(w),read(e);
			++q;

			B[q].push_back(I);
			tr[I].c=e;
			tr[I].v=w;
			Splay(q);
			tr[tr[q].r].fa=I;
			tr[I].r=tr[q].r;
			tr[q].r=I;
			tr[I].fa=q;
			merge(I);
			merge(q);
		}else{
			read(q),read(w);
			++q;

			int W=w;
			LL ans=0;

			while(tr[q].v && w)
			{
				Splay(q);
				if(w>=tr[tr[q].mi].v)
				{
					ans+=(LL)tr[tr[q].mi].v*tr[tr[q].mi].c;
					w-=tr[tr[q].mi].v;
					tr[tr[q].mi].v=0;
					int nw=tr[q].mi;
					for(int i=0;i<(int)B[nw].size();++i)
					{
						int q=B[nw][i];
						Splay(q);

						tr[tr[q].l].fa=0;
						tr[q].l=0;

						merge(q);
					}
				}else{
					tr[tr[q].mi].v-=w;
					ans+=(LL)w*tr[tr[q].mi].c;
					w=0;
				}
			}

			printf("%d %lld\n",W-w,ans);
			fflush(stdout);
		}
	}


	return 0;
}