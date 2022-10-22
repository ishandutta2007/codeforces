#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 2100005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

const ll mod=998244353;
const int G=3,Ginv=332748118;

int n,m,L,R[maxn];
int a[maxn],b[maxn],N;

inline ll pw(ll a,ll b)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1) ans=(ans*base)%mod;
		base=(base*base)%mod; b>>=1;
	}
	return ans;
}

inline void NTT(int *A,int f)
{
	rep(i,0,N-1) if(i<R[i]) swap(A[i],A[R[i]]);
	for(int i=1;i<N;i<<=1)
	{
		int gn=pw(f==1?G:Ginv,(mod-1)/(i<<1));
		for(int j=0;j<N;j+=(i<<1))
		{
			int g=1;
			for(int k=0;k<i;k++,g=1ll*g*gn%mod)
			{
				int x=A[j+k],y=1ll*g*A[i+j+k]%mod;
				A[j+k]=(x+y)%mod; A[i+j+k]=(x-y+mod)%mod;
			}
		}
	}
	if(f==-1)
	{
		int inv=pw(N,mod-2);
		rep(i,0,N-1) A[i]=1ll*inv*A[i]%mod;
	}
}

inline void Mul(int *A,int *B)
{
	NTT(A,1); NTT(B,1);
	rep(i,0,N-1) a[i]=1ll*a[i]*b[i]%mod; NTT(a,-1);
}

int x[maxn],v[maxn],F;
vector <int> ans;

int main()
{
	n=read(); m=read();
	rep(i,1,n) x[i]=read(),v[x[i]]=1;
	rep(i,1,n)
	{
		for(int j=x[i];j<=m;j+=x[i])
		{
			a[j]=1;
			if(!v[j]) {F=1; break;}
		}
	}
	if(F) {puts("NO"); return 0;}
	a[0]=1; rep(i,0,m) b[i]=a[i];
	for(N=1;N<=2*m;N<<=1) L++;
	rep(i,0,N-1) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	Mul(a,b);
	rep(i,1,m)
	{
		if(a[i]&&(!v[i])) F=1;
		if(a[i]>2) v[i]=0;
	}
	rep(i,1,m) if(v[i]) ans.pb(i);
	if(F) puts("NO");
	else
	{
		puts("YES");
		printf("%d\n",ans.size());
		for(auto x:ans) printf("%d ",x);
	}
	return 0;
}