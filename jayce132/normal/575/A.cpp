#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;

int mod;

struct matrix {
	int a[2][2];
	inline int* operator [](int index){ return a[index];} 
	matrix(int op=0){ memset(a,0,sizeof(a)); a[0][0]=a[1][1]=op;}
};

inline matrix operator *(matrix a,matrix b)
{
	matrix c(0);
	REP(i,0,1)REP(j,0,1)
		c[i][j]=(1ll*a[i][0]*b[0][j]+1ll*a[i][1]*b[1][j])%mod;
	return c;
}

ll K;
int n;

int s[maxn];
matrix pre[maxn],suf[maxn];
matrix a[maxn];

inline matrix Matrix(int s1,int s0)
{
	matrix c;
	c[0][0]=0; c[1][0]=1;
	c[1][1]=s1; c[0][1]=s0;
	return c;
}

struct node {
	matrix s;
};
node c[(1<<18)+20];
#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

void make_tree(int o,int l,int r)
{
	if(l==r)return c[o].s=a[l],void();
	int mid=l+r>>1; 
	make_tree(left);
	make_tree(right);
	c[o].s=c[lc].s*c[rc].s;
}

matrix query(int ql,int qr,int o,int l,int r)
{
	if(ql<=l && r<=qr)return c[o].s;
	int mid=l+r>>1;
	if(qr<=mid)return query(ql,qr,left);
	else if(ql>mid)return query(ql,qr,right);
	else return query(ql,qr,left)*query(ql,qr,right);
}

inline void init()
{
	cin>>K; mod=read();
	n=read();
	REP(i,0,n-1)s[i]=read();
	REP(i,0,n-1)a[i]=Matrix(s[(i+1)%n],s[(i)%n]);
	pre[0]=a[0]; REP(i,1,n-1)pre[i]=pre[i-1]*a[i];
	suf[n]=matrix(1); DREP(i,n-1,0)suf[i]=a[i]*suf[i+1];
	make_tree(1,0,n-1);
}

inline matrix power(matrix a,ll b)
{
	matrix ans(1);
	while(b)
	{
		if(b&1)ans=ans*a;
		b>>=1;
		a=a*a;
	}
	return ans;
}

inline matrix Solve(ll l,ll r)
{
	r--;
	if(l>r)return matrix(1);
	ll idl=l/n,idr=r/n;
	if(idl==idr)return query(l%n,r%n,1,0,n-1);
	matrix ans(1);
	ans=suf[l%n]*power(pre[n-1],idr-idl-1)*pre[r%n];
	return ans;
}

pair<ll,ll> J[maxn];

inline void doing()
{
	matrix ans(1);
	int m=read();
	ll lst=0;
	if(K==0)puts("0"),exit(0);
	REP(i,1,m)scanf("%lld%lld",&J[i].fi,&J[i].se);
	sort(J+1,J+m+1);
	J[m+1].fi=K+10000;
	REP(i,1,m)
	{
		ll j=J[i].fi,v=J[i].se;
		if(j>K)break;
		if(lst<=j-1)
		{
			ans=ans*Solve(lst,j-1)*Matrix(v,s[(j-1)%n]);
			if(j<K && J[i+1].fi!=j+1)ans=ans*Matrix(s[(j+1)%n],v);
		}else {
			if(i)ans=ans*Matrix(v,J[i-1].se);
			if(j<K && J[i+1].fi!=j+1)ans=ans*Matrix(s[(j+1)%n],v);
		}
		lst=j+1;
	}
	if(lst<K)ans=ans*Solve(lst,K);
	printf("%d\n",ans[1][0]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}