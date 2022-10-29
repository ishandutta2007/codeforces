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
const int N=20010;
int n,k;
i64 a[N];
i64 q(int a,int b){ printf("and %d %d\nor %d %d\n",a,b,a,b); fflush(stdout); return read()+read(); }
int main()
{
	n=read(); k=read();
	i64 v1=q(1,2),v2=q(1,3),v3=q(2,3),v=(v1+v2+v3)/2;
	a[3]=v-v1; a[2]=v-v2; a[1]=v-v3;
	fr(i,4,n) a[i]=q(1,i)-a[1];
	std::sort(a+1,a+n+1);
	printf("finish %I64d\n",a[k]);
	return 0;
}