#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (1300000+10)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
int father[MAXN];
int getfather(int x)
{
	if (father[x]==x) return x;
	father[x]=getfather(father[x]);
	return father[x];
}
struct node
{
	ll v;
	int dis,ch[2];
	node():v(0),dis(0){ch[0]=ch[1]=0;}
	node(ll _v):v(_v),dis(0){ch[0]=ch[1]=0;}
}q[MAXN];
int merge(int a,int b)
{
	if (a==0||b==0) return a+b;
	if (q[a].v<q[b].v) swap(a,b);
	q[a].ch[1]=merge(q[a].ch[1],b);
	if (q[q[a].ch[0]].dis<q[q[a].ch[1]].dis) swap(q[a].ch[0],q[a].ch[1]);
	if (q[a].ch[1]) q[a].dis=q[q[a].ch[1]].dis+1;else q[a].dis=0;
	return a;
}
int root[MAXN],tot=0;
int pop(int a)
{
	int p=merge(q[a].ch[0],q[a].ch[1]);
	return p;
}
int n,siz[MAXN],l[MAXN],r[MAXN];
ll a[MAXN];
ll abs2(ll a,ll b){return a-b>0?a-b:b-a;}
int main()
{
//	freopen("bzoj1367.in","r",stdin);
	scanf("%d",&n);
	For(i,n) scanf("%I64d",&a[i]),a[i]-=(long long)i,father[i]=i,q[i].v=a[i];
	For(i,n)
	{
		siz[++tot]=1;root[tot]=i;l[tot]=r[tot]=i;
		while (tot>1&&q[root[tot]].v<=q[root[tot-1]].v)
		{
			int ru=root[tot-1],rv=root[tot];
			Fork(j,l[tot],r[tot])
			{
				q[j]=node(a[j]);
				ru=merge(ru,j);
			}
			siz[tot-1]+=r[tot]-l[tot]+1;r[tot-1]=r[tot];tot--;
			while (siz[tot]>(r[tot]-l[tot]+2)/2) ru=pop(ru),siz[tot]--;
			root[tot]=ru;			
		}
//		For(i,tot) cout<<l[i]<<' '<<r[i]<<' '<<q[root[i]].v<<endl;	cout<<endl;
	}
	//For(i,n) cout<<a[i]<<' ';cout<<endl;
	//For(i,tot) cout<<siz[i]<<' ';cout<<endl;
	
	//For(i,tot) cout<<l[i]<<' '<<r[i]<<' '<<q[root[i]].v<<endl;	
	
	ll ans=0;
	For(i,tot)
	{
		Fork(j,l[i],r[i]) ans+=abs2(q[root[i]].v,a[j]);
	}
	printf("%I64d\n",ans);
	return 0;
}