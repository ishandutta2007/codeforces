#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 2500005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

inline void write(ll x)
{
	if(x<0) {putchar('-'); return write(-x);}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

char mp[25][maxn];
int a[maxn],b[maxn],cnt[maxn],N,ans,n,m;
const ll mod=998244353;
const ll inv2=499122177;

inline void XOR(int *A,int opt)
{
	for(int i=1;i<N;i<<=1)
		for(int j=0;j<N;j+=(i<<1))
			for(int k=0;k<i;k++)
			{
				int x=A[j+k],y=A[i+j+k];
				A[j+k]=(x+y)%mod; A[i+j+k]=(x-y+mod)%mod;
				if(opt==-1) A[j+k]=(A[j+k]*inv2)%mod,A[i+j+k]=(A[i+j+k]*inv2)%mod;
			}
}

int main()
{
	n=read(); m=read(); rep(i,1,n) scanf("%s",mp[i]+1); int ed=(1<<n)-1;
	rep(i,1,m)
	{
		int tmp=0;
		rep(j,1,n) tmp=tmp*2+(mp[j][i]-'0');
		a[tmp]++;
	}
	rep(i,1,ed) cnt[i]=(cnt[i>>1]+(i&1)),b[i]=min(cnt[i],n-cnt[i]);
	N=ed+1; XOR(a,1); XOR(b,1); ans=inf;
	rep(i,0,N-1) a[i]=(1ll*a[i]*b[i])%mod; XOR(a,-1);
	rep(i,0,N-1) ans=min(ans,a[i]); cout<<ans<<endl;
	return 0;
}