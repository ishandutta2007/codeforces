#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
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

const int mod=1004535809;
const int G=3,Ginv=334845270;
const int maxn=(1<<20)+1;

ll L,R[maxn],N,fac[maxn],Inv[maxn],Iv[maxn];

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

inline void NTT(vi &A,int f)
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

inline vi FIX(vi A,int num)
{
	A.resize(num);
	return A;
}

inline vi operator * (vi A,vi B)
{
	if(A.empty()||B.empty()) return vi();
	int nn=A.size(),mm=B.size();
	L=0; for(N=1;N<=nn+mm;N<<=1) L++;
	rep(i,0,N-1) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	A.resize(N); B.resize(N); NTT(A,1); NTT(B,1);
	for(int i=0;i<N;i++) A[i]=1ll*A[i]*B[i]%mod; NTT(A,-1);
	vi C; C.clear();
	rep(i,0,nn+mm-2) C.pb(A[i]);
	return C;
}

inline vi operator + (vi a, vi b)
{
    a.resize(max(a.size(),b.size()));
    rep(i,0,(int)b.size()-1) a[i]=(a[i]+b[i])%mod;
    return a;
}

inline vi operator - (vi A,vi B)
{
	A.resize(max(A.size(),B.size()));
	rep(i,0,(int)B.size()-1) A[i]=(A[i]-B[i]+mod)%mod;
	return A;
}

inline vi operator * (vi A,int x)
{
	int nn=A.size(); vi C; C.clear();
	for(int i=0;i<nn;i++) C.pb(1ll*A[i]*x%mod);
	return C;
}

inline vi polyinv(vi A)
{
	int nn=(int)A.size(); vi B,C; B.clear(); C.clear();
	if(nn==1) {B.pb(pw(A[0],mod-2)); return B;}
	B=polyinv(FIX(A,(nn+1)/2));
	return FIX(B*2-B*B*A,nn);
}

inline vi polypow(vi a,int b)
{
	vi ans,base=a; ans.clear(); ans.pb(1ll);
	while(b)
	{
		if(b&1)
		{
			ans=ans*base;
			rep(i,0,ans.size()-1) if(ans[i]) ans[i]=1;
		}
		base=base*base; b>>=1;
		rep(i,0,base.size()-1) if(base[i]) base[i]=1;
	}
	return ans;
}

vi a,b,c;
int n,k;

int main()
{
	n=read(); k=read(); int x; rep(i,0,1001) a.pb(0);
	rep(i,1,n) x=read(),a[x]++; c=polypow(a,k);
	for(int i=0;i<c.size();i++) if(c[i]) printf("%d ",i);
	return 0;
}