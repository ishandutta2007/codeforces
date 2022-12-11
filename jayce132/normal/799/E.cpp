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
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;

int n,m,k;
int val[maxn],sx[maxn],tx;
int col[maxn];

vector<int>AB;
vector<int>A,B;

struct node {
	int s; ll s1;
	inline void Merge(node lc,node rc ) {
		s=lc.s+rc.s;
		s1=lc.s1+rc.s1;
	}
};
node c[1<<20];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

void update(int x,int d,int o,int l,int r)
{
	c[o].s+=d; c[o].s1+=d*sx[x];
	if(l==r)return ;
	int mid=l+r>>1;
	if(x<=mid)update(x,d,left);
	else update(x,d,right);
}

inline bool cmp(int x,int y){ return val[x]<val[y];}

inline void init()
{
	n=read();m=read();k=read();
	REP(i,1,n)val[i]=read(),sx[++tx]=val[i];
	int ka,kb;
	ka=read(); REP(i,1,ka)col[read()]|=1;
	kb=read(); REP(i,1,kb)col[read()]|=2;
	if(ka<k || kb<k)puts("-1"),exit(0);
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-(sx+1);
	REP(i,1,n)val[i]=lower_bound(sx+1,sx+tx+1,val[i])-sx;
	REP(i,1,n)
	{
		if(col[i]==0)update(val[i],1,1,1,tx);
		else if(col[i]==1)A.push_back(i);
		else if(col[i]==2)B.push_back(i);  
		else AB.push_back(i);
	}
	sort(A.begin(),A.end(),cmp);
	sort(B.begin(),B.end(),cmp);
	sort(AB.begin(),AB.end(),cmp);
}

ll All;
ll ans;

ll query(int k,int o,int l,int r)
{
	if(l==r)return (ll)k*sx[l];
	int mid=l+r>>1;
	if(c[lc].s>=k)return query(k,left);
	else return c[lc].s1+query(k-c[lc].s,right);
}

inline void doing()
{
	int j=min(min((int)A.size(),(int)B.size()),k)-1;
	REP(i,0,j)All+=sx[val[A[i]]],All+=sx[val[B[i]]];
	REP(i,j+1,n)
	{
		if(i<(int)A.size())update(val[A[i]],1,1,1,tx);
		if(i<(int)B.size())update(val[B[i]],1,1,1,tx);
	}
	REP(i,0,k-j-2)All+=sx[val[AB[i]]];
	REP(i,k-j-1,(int)AB.size()-1)update(val[AB[i]],1,1,1,tx);

	ans=1ll<<60;
	if(k+j+1<=m)chkmin(ans,All+query(m-k-j-1,1,1,tx));
	
	REP(i,k-j-1,min((int)AB.size()-1,k-1))
	{
		All+=sx[val[AB[i]]];
		update(val[AB[i]],-1,1,1,tx);
		update(val[A[j]],1,1,1,tx); All-=sx[val[A[j]]];
		update(val[B[j]],1,1,1,tx); All-=sx[val[B[j]]];
		j--;
		if(k+j+1<=m)chkmin(ans,All+query(m-k-j-1,1,1,tx));
	}
	if(ans!=(1ll<<60))printf("%lld\n",ans);
	else puts("-1");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("gjb.in","r",stdin);
	freopen("gjb.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}