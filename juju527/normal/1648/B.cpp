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
const int N=1000010;
int a[N],s[N];
int main()
{
	fr(T,1,read())
	{
		int n=read(),c=read(); bool flag=1;
		fr(i,0,c+10) a[i]=s[i]=0;
//		fr(i,1,c) a[i]=1;
		fr(i,1,n) a[read()]++;
		fr(i,1,c) s[i]=s[i-1]+a[i];
		fr(i,1,c) if(!a[i]) fr(j,1,c/i) if(a[j]&&s[i*j-1]!=s[std::min((i+1)*j-1,c)]) flag=0;
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}