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
#define int long long
const int N=200010; const i64 inf=1ll<<60;
int n;
int a[N],s[N];
int check(int u)
{
	if(s[n]!=(n+u)/2) return inf;
	int ans=0;
	fr(i,1,n) ans+=std::abs(s[i]-((i+u)/2));
	return ans;
}
signed main()
{
	fr(T,1,read())
	{
		n=read();
		fr(i,1,n) s[i]=s[i-1]+(read()&1);
		int ans=std::min(check(0),check(1));
		printf("%I64d\n",ans==inf?-1:ans);
	}
	return 0;
}