#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e6+20;
const ll inf=1ll<<60;

int n,m,p;
int a[maxn];

#define pll pair<ll,ll>

struct node {
	vector<ll>R,B;
	inline void Merge(node a,node b)
	{
		int n=SZ(a.R)-1,m=SZ(b.R)-1,j=0;
		ll lst=-inf;
		REP(i,0,n)
		{
			while(j<=m)
			{
				ll x=b.R[j]-a.B[i];
				if(x>=lst)
				{
					R.push_back(min(x,a.R[i]));
					B.push_back(a.B[i]+b.B[j]);
				}
				if(x>=a.R[i])break;
				j++;
			}
			if(j)j--;
			lst=a.R[i];
		}
		vector<ll>nR,nB;
		nR.push_back(R.front()); nB.push_back(B.front());
		int t=0;
		REP(i,1,SZ(R)-1)if(B[i]==nB.back())
			nR[t]=R[i];
		else nR.push_back(R[i]),nB.push_back(B[i]),++t;
		R=nR; B=nB;
	}
};
node c[(1<<21)+20];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

void make_tree(int o,int l,int r)
{
	if(l==r)return c[o].R={p-a[l]-1,inf},c[o].B={a[l],a[l]-p},void();
	int mid=l+r>>1;
	make_tree(left);
	make_tree(right);
	c[o].Merge(c[lc],c[rc]);
}

inline void init()
{
	n=read();m=read();p=read();
	REP(i,1,n)a[i]=read();
	make_tree(1,1,n);
}

void query(int ql,int qr,ll &x,int o,int l,int r)
{
	if(ql<=l && r<=qr)
	{
		int t=lower_bound(c[o].R.begin(),c[o].R.end(),x)-c[o].R.begin();
		x+=c[o].B[t];
		return;
	}
	int mid=l+r>>1;
	if(ql<=mid)query(ql,qr,x,left);
	if(qr>mid)query(ql,qr,x,right);
}

inline void doing()
{
	REP(i,1,m)
	{
		int l=read(),r=read();
		ll ans=0;
		query(l,r,ans,1,1,n);
		printf("%lld\n",ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("bug.in","r",stdin);
	freopen("bug.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}