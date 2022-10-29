#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int x; scanf("%d",&x); return x;
}
int main()
{
	fr(T,1,read())
	{
		int a=read(),b=read(),c=read(),d=read(),ans=0;
		ans=std::abs(c-a)+std::abs(d-b);
		if(a!=c&&b!=d) ans+=2; 
		printf("%d\n",ans);
	}
	return 0;
}