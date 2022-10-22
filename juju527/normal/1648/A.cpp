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
const int N=100010;
std::map<int,int> c,l[N],h[N],s;
i64 ans,Ans;
int n,m;
int main()
{
	n=read(); m=read();
	fr(i,1,n) fr(j,1,m)
	{
		int v=read();
		l[i][v]++; h[j][v]++; s[v]++;
	}
	c.clear(); Ans=0;
	fr(i,1,n-1)
	{
		for(auto v:l[i])
		{
			Ans-=c[v.first]*(i64)(s[v.first]-c[v.first]);
			c[v.first]+=v.second;
			Ans+=c[v.first]*(i64)(s[v.first]-c[v.first]);
		}
		ans+=Ans;
	}
	c.clear(); Ans=0;
	fr(i,1,m-1)
	{
		for(auto v:h[i])
		{
			Ans-=c[v.first]*(i64)(s[v.first]-c[v.first]);
			c[v.first]+=v.second;
			Ans+=c[v.first]*(i64)(s[v.first]-c[v.first]);
		}
		ans+=Ans;
	}
	printf("%I64d\n",ans);
	return 0;
}