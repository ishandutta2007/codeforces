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
int n;
char s[N],c[N];
int a[N];
int main()
{
	fr(T,1,read())
	{
		n=read(); fr(i,1,n) a[i]=0;
		scanf("%s%s",s+1,c+1);
		fr(i,1,n) if(s[i]==c[i]) a[i]=s[i]-48; else a[i]=2;
		fr(i,1,n-1) if(a[i]+a[i+1]==1){ a[i]=2; a[i+1]=-2; }
		int ans=0;
		fr(i,1,n) ans+=(a[i]==0)+(a[i]==2)*2;
		printf("%d\n",ans);
	}
	return 0;
}