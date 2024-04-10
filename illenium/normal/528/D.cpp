#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const char K[4]={'A','G','C','T'};
const ll mod=998244353;
const ll G=3,Ginv=332748118;

char s[maxn],t[maxn];
int n,m,k,a[maxn],b[maxn],R[maxn],N,c[maxn],tt[maxn],ans,L;

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

int main()
{
	cin>>n>>m>>k; scanf("%s",s); scanf("%s",t); reverse(t,t+m);
	for(N=1;N<=n+m;N<<=1) L++;
	rep(i,0,N-1) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	rep(T,0,3)
	{
		rep(i,0,N-1) c[i]=0,a[i]=0,b[i]=0;
		rep(i,0,n) if(s[i]==K[T])
		{
			int l=max(0,i-k),r=min(n,i+k);
			c[l]++; c[r+1]--;
		}
		rep(i,0,m) if(t[i]==K[T]) b[i]=1;
		int nw=0;
		rep(i,0,n) {nw+=c[i]; if(nw) a[i]=1;}
		NTT(a,1); NTT(b,1);
		rep(i,0,N-1) a[i]=1ll*a[i]*b[i]%mod; NTT(a,-1);
		rep(i,0,N-1) tt[i]+=a[i];
	}
	rep(i,0,n-1) ans+=(tt[i]==m); cout<<ans<<endl;
	return 0;
}