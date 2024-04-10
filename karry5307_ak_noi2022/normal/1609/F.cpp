#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int cntbit(long long x){int ans=0;while(x)ans++,x&=(x-1);return ans;}

struct item
{
	int pos,l,r,v;item(int _pos=0,int _l=0,int _r=0,int _v=0):pos(_pos),l(_l),r(_r),v(_v){}
};
bool operator<(item A,item B){return A.pos<B.pos;}
vector<item> MAXN,MINN;

long long a[2000000];

int lmax[2000000],lmin[2000000],rmax[2000000],rmin[2000000];

vector<int> pos[64];

struct BIT
{
	int n,c[1500000];long long d[1500000];
	void init(int N){n=N;for(int i=1;i<=n;i++)c[i]=d[i]=0;}
	void add(int x,int y)
	{
    	for(int i = x;i <= n;i += i&-i) c[i] += y, d[i] += (long long)x*y;
	}
	long long query(int x)
	{
    	long long y = 0;
    	for(int i = x;i;i -= i&-i) y += (long long)(x+1)*c[i]-d[i];
    	return y;
	}
	long long query(int l,int r){return query(r)-query(l-1);}
}B[2];

long long val;
void modify(int id,int l,int r,int v)
{
	val+=v*B[id^1].query(l,r);B[id].add(l,v),B[id].add(r+1,-v);
}


int main()
{
	int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	vector<int> V;V.push_back(0);
	for(int i=1;i<=n;i++)
	{
		while(V.back()!=0&&a[i]>=a[V.back()])V.pop_back();lmin[i]=V.back()+1;V.push_back(i);
	}
	V.clear();V.push_back(0);
	for(int i=1;i<=n;i++)
	{
		while(V.back()!=0&&a[i]<=a[V.back()])V.pop_back();lmax[i]=V.back()+1;V.push_back(i);
	}
	V.clear();V.push_back(n+1);
	for(int i=n;i>=1;i--)
	{
		while(V.back()!=n+1&&a[i]>a[V.back()])V.pop_back();rmin[i]=V.back()-1;V.push_back(i);
	}
	V.clear();V.push_back(n+1);
	for(int i=n;i>=1;i--)
	{
		while(V.back()!=n+1&&a[i]<a[V.back()])V.pop_back();rmax[i]=V.back()-1;V.push_back(i);
	}
	//for(int i=1;i<=n;i++)printf("%d %d %d %d\n",lmax[i],lmin[i],rmax[i],rmin[i]);puts("");
	for(int i=1;i<=n;i++)pos[cntbit(a[i])].push_back(i);
	
	long long ans=0;
	for(int i=0;i<64;i++)
	{
		if(pos[i].empty())continue;
		V.clear(),MAXN.clear(),MINN.clear();
		for(int j=0;j<pos[i].size();j++)
		{
			int u=pos[i][j];
			V.push_back(lmax[u]),V.push_back(lmin[u]),V.push_back(u+1);
			MAXN.push_back(item(lmax[u],u,rmax[u],1)),MAXN.push_back(item(u+1,u,rmax[u],-1));
			MINN.push_back(item(lmin[u],u,rmin[u],1)),MINN.push_back(item(u+1,u,rmin[u],-1));
		}
		sort(V.begin(),V.end());V.erase(unique(V.begin(),V.end()),V.end());
		sort(MAXN.begin(),MAXN.end()),sort(MINN.begin(),MINN.end());
		B[0].init(n),B[1].init(n);val=0;
		for(int j=0,pmaxn=0,pminn=0;j<V.size()-1;j++)
		{
			while(pmaxn<MAXN.size()&&MAXN[pmaxn].pos==V[j])
			{
				modify(0,MAXN[pmaxn].l,MAXN[pmaxn].r,MAXN[pmaxn].v);
				pmaxn++;
			}
			while(pminn<MINN.size()&&MINN[pminn].pos==V[j])
			{
				modify(1,MINN[pminn].l,MINN[pminn].r,MINN[pminn].v);
				pminn++;
			}
			ans+=(V[j+1]-V[j])*val;
		}
		//printf("%lld\n",ans);
	}
	printf("%lld",ans);
}