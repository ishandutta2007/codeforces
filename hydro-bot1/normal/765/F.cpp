// Hydro submission #62c5649bc3a9fda562296c6a@1657103516192
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef unsigned long long ULL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')	f=(c=='-'?-1:f),c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(int x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const int Up=1e9;
#define mp make_pair
int cnt,rt;
int lc[3000005],rc[3000005],maxn[3000005];
vector<pair<int,int>> Q[100005];
int n,a[100005],m,ans[300005];
inline int lowbit(int x){return x&(-x);}
struct BinaryIndexedTree{
	int tr[100005];
	void init(){for(int i=1;i<=n;++i)	tr[i]=Up;}
	void modify(int x,int v){for(int i=x;i;i^=lowbit(i))	tr[i]=min(tr[i],v);}
	int query(int x){int ret=Up;for(int i=x;i<=n;i+=lowbit(i))	ret=min(ret,tr[i]);return ret;}
}bit;
#define Mm int mid=(l+r)>>1
void modify(int l,int r,int &now,int p,int v)
{
	if(!now)	now=++cnt;
	maxn[now]=max(maxn[now],v);
	if(l==r)	return ;
	Mm;
	if(p<=mid)	modify(l,mid,lc[now],p,v);
	else	modify(mid+1,r,rc[now],p,v);
}
int query(int l,int r,int now,int x,int y)
{
	if(!now)	return 0;
	if(x<=l && r<=y)	return maxn[now];
	Mm,ret=0;
	if(x<=mid)	ret=max(ret,query(l,mid,lc[now],x,y));
	if(mid<y)	ret=max(ret,query(mid+1,r,rc[now],x,y));
	return ret;
}
#undef Mm
void Cope()
{
	bit.init();
	for(int i=1;i<=cnt;++i)	lc[i]=rc[i]=maxn[i]=0;
	cnt=rt=0;
	for(int i=1;i<=n;++i)
	{
		int pos=query(0,Up,rt,a[i],Up);
		while(pos)
		{
			bit.modify(pos,a[pos]-a[i]);
			pos=query(0,Up,rt,a[i],(a[i]+a[pos])/2-int((a[i]+a[pos])%2==0));
		}
		modify(0,Up,rt,a[i],i);
		for(auto st:Q[i])	ans[st.second]=min(ans[st.second],bit.query(st.first));
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	m=read();
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read();
		Q[r].push_back(mp(l,i));
		ans[i]=Up;
	}
	Cope();
	for(int i=1;i<=n;++i)	a[i]=Up-a[i];
	Cope();
	for(int i=1;i<=m;++i)	write(ans[i]),puts("");
	return 0;
}