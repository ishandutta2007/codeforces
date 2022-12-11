#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=5e5+20;
const int inf=0x3f3f3f3f;

char str[maxn];
int n;

int x[maxn],y[maxn],tag[maxn],v[maxn<<1],sa[maxn],rk[maxn],ht[maxn];

inline void get_sa()
{
	int m=26;
	REP(i,1,n)tag[x[i]=str[i]-'a'+1]++;
	REP(i,1,m)tag[i]+=tag[i-1];
	DREP(i,n,1)sa[tag[x[i]]--]=i;
	
	for(int j=1,p=0;p<n;m=p,j<<=1)
	{
		p=0; REP(i,n-j+1,n)y[++p]=i;
		REP(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
		REP(i,0,m)tag[i]=0;
		REP(i,1,n)tag[v[i]=x[y[i]]]++;
		REP(i,1,m)tag[i]+=tag[i-1];
		DREP(i,n,1)sa[tag[v[i]]--]=y[i];
		p=1; REP(i,1,n)v[i]=x[i]; x[sa[1]]=1;
		REP(i,2,n)x[sa[i]]=v[sa[i]]==v[sa[i-1]] && v[sa[i]+j]==v[sa[i-1]+j]?p:++p;
	}
	REP(i,1,n)rk[sa[i]]=i;
	int j=0;
	REP(i,1,n)
	{
		if(j)j--;
		if(rk[i]==n)continue;
		while(i+j<=n && sa[rk[i]+1]+j<=n && str[i+j]==str[sa[rk[i]+1]+j])j++;
		ht[rk[i]]=j;
	}

}

inline void init()
{
	n=read();
	scanf("%s",str+1);
	get_sa();
}

struct node {
	int mx;
	int ht;
	inline void Merge(node lc,node rc) {
		mx=max(lc.mx,rc.mx);
	}
};
node c[maxn<<2];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

void make_tree(int o,int l,int r)
{
	if(l==r)return c[o].ht=ht[l],void();
	int mid=(l+r)>>1;
	make_tree(left);
	make_tree(right);
	c[o].ht=min(c[lc].ht,c[rc].ht);
}


int dp[maxn];

int queryR(int ql,int qr,int &mn,int d,int o,int l,int r)
{
	if(ql>qr)return 0;
 	if(ql<=l && r<=qr)
	{
		if(c[o].ht>=d)return chkmin(mn,c[o].ht),c[o].mx;
		if(l==r)return chkmin(mn,c[o].ht),0;
	}
	int mid=(l+r)>>1,ans=0;
	if(qr>mid)
	{
		chkmax(ans,queryR(ql,qr,mn,d,right));
		if(mn<d)return ans;
	}
	if(ql<=mid)
	{
		chkmax(ans,queryR(ql,qr,mn,d,left));
	}
	return ans;
}

int queryL(int ql,int qr,int &mn,int d,int o,int l,int r)
{
	if(ql>qr)return 0;
	if(ql<=l && r<=qr)
	{
		if(c[o].ht>=d)return chkmin(mn,c[o].ht),c[o].mx;
		if(l==r)return chkmin(mn,c[o].ht),c[o].mx;
	}
	int mid=(l+r)>>1,ans=0;
	if(ql<=mid)
	{
		chkmax(ans,queryL(ql,qr,mn,d,left));
		if(mn<d)return ans;
	}
	if(qr>mid)
	{
		chkmax(ans,queryL(ql,qr,mn,d,right));
	}
	return ans;
}

void update(int x,int d,int o,int l,int r)
{
	if(l==r)return chkmax(c[o].mx,d),void();
	int mid=(l+r)>>1;
	if(x<=mid)update(x,d,left);
	else update(x,d,right);
	c[o].Merge(c[lc],c[rc]);
}

inline void doing()
{
	int ans=1,Ans=ans;
	dp[n]=1;
	make_tree(1,1,n);
	DREP(i,n-1,1)
	{
		++ans;
		int tmp=0,t=inf,t1=inf;
		do{
			t=t1=inf;
			tmp=max(queryR(1,rk[i+1]-1,t,ans-1,1,1,n),queryL(rk[i+1],n,t1,ans-1,1,1,n))+1;
			t=t1=inf;
			chkmax(tmp,max(queryR(1,rk[i]-1,t,ans-1,1,1,n),queryL(rk[i],n,t1,ans-1,1,1,n))+1);
			if(tmp<ans)
			{
				ans--;update(rk[i+ans],dp[i+ans],1,1,n);
			}else break;
		}while(1);
		dp[i]=ans;
		chkmax(Ans,ans);
	}
	printf("%d\n",Ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}