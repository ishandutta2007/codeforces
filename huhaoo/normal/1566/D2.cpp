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
const int N=310;
int n,m,a[N*N],b[N][N],p[N*N];
int main()
{
	fr(T,1,read())
	{
		n=read(); m=read();
		fr(i,1,n*m) a[i]=read(),p[i]=i;
		std::sort(p+1,p+n*m+1,[&](int x,int y){ return a[x]==a[y]?x<y:a[x]<a[y]; });
		fr(i,1,n) for(int j=1,k=1;j<=m;)
		{
			while(k<=m&&a[p[(i-1)*m+j]]==a[p[(i-1)*m+k]]) k++;
			std::reverse(p+(i-1)*m+j,p+(i-1)*m+k); j=k;
		}
		int ans=0;
		fr(i,1,n) fr(j,1,m) fr(k,1,j-1) if(p[(i-1)*m+j]>p[(i-1)*m+k]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}