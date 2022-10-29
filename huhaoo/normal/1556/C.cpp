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
i64 n,c[N],ans;
int main()
{
	n=read();
	fr(i,1,n) c[i]=read();
	fr(i,1,n) if(i%2==0)
	{
		i64 j=i+1,s1=0,s2=0,v=0;
		while(j<=n)
		{
			v=std::max(s1-s2+c[j-1],v);
			s1+=c[j-1]; s2+=c[j];
			ans+=std::max(0ll,std::min(c[i-1]-v+1,c[j+1]-(s2-s1+v)+1));
			j+=2;
		}
	}
	else ans+=std::min(c[i],c[i+1]);
	printf("%I64d\n",ans);
	return 0;
}