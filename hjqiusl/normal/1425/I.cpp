#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
int a[N],t[N],st[N],ed[N],cntdfn=0,deep[N];
void dfs(int now)
{
	st[now]=++cntdfn;
	for (int to:e[now]) deep[to]=deep[now]+1,dfs(to);
	ed[now]=cntdfn;
}
void shuffle_p(int *a,int *p,int n)
{
	static int b[N];
	memcpy(b,a,sizeof(int)*(n+1));
	for (int i=1;i<=n;i++) a[p[i]]=b[i];
}

signed main()
{
	int n=read(),Q=read();
	for (int i=1;i<=n;i++) a[i]=read(),t[i]=0;
	for (int i=2;i<=n;i++) e[read()].push_back(i);
	dfs(1);
	shuffle_p(a,st,n);
	shuffle_p(deep,st,n);
	for (int T=1;T<=Q;T++)
	{
		int x=read(),ans1=0,ans2=0;
		for (register int L=st[x],R=ed[x],i=L;i<=R;i++)
		if (t[i]<=T)
		{
			ans1++,ans2+=deep[i];
			t[i]=T+a[i];
		}
		ans2-=ans1*deep[st[x]];
		print(ans2,' '),print(ans1);
	}
	
	return 0;
}
/*
>B O(Q/B)
<B  a_i  Beats t_i<=now  t_i  now+a_iO(Blog)
O(Qsqrt(nlog))
 nq  nq 
*/