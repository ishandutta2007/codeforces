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
int main()
{
	fr(T,1,read())
	{
		static int n,a[100010],b[100010],c[100010],n1,n2;
		n=read(); n1=(n+1)/2; n2=n-n1;
		fr(i,1,n) a[i]=read();
		fr(i,1,n1) b[i]=a[i+i-1];
		fr(i,1,n2) c[i]=a[i+i];
		std::sort(b+1,b+n1+1); std::sort(c+1,c+n2+1);
		fr(i,1,n1) a[i+i-1]=b[i];
		fr(i,1,n2) a[i+i]=c[i];
		int flag=1;
		fr(i,2,n) if(a[i]<a[i-1]) flag=0;
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}