#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=(r<<3)+(r<<1)+(c^48); c=getchar(); }
	return r*t;
}
const int N=200010,mod=998244353;
i64 power(i64 a,i64 b,i64 p=mod)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a,mod-2); }
i64 f[N];
int n,m,s[N],t[N];
int b[N];
void add(int p,int v){ for(;p<N;p+=p&(-p)) b[p]+=v; }
int query(int p){ if(p<=0) return 0; int ans=0; for(;p;p-=p&(-p)) ans+=b[p]; return ans; }
i64 ans,Ans;
int main()
{
	n=read(); m=read();
	fr(i,1,n) s[read()]++;
	fr(i,1,m) t[i]=read();
	if(m>n) t[n]++;
	f[0]=1; fr(i,1,n) f[i]=f[i-1]*i%mod;
	Ans=1; fr(i,1,N-10) if(s[i]){ add(i,s[i]); Ans=Ans*inv(f[s[i]])%mod; }
	fr(i,1,n)
	{
		ans+=query(t[i]-1)*Ans%mod*f[n-i]%mod;
		if(s[t[i]]){ Ans=Ans*s[t[i]]%mod; add(t[i],-1); s[t[i]]--; } else break;
	}
	printf("%d\n",int(ans%mod));
	return 0;
}