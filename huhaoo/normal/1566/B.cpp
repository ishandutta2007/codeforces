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
char s[N];
int main()
{
	fr(T,1,read())
	{
		scanf("%s",s+1); n=strlen(s+1);
		int p1=0,p2=0,p3=0;
		fr(i,1,n)
			if(s[i]=='0')
			{
				p1=1;
				if(p2) p3=1;
			}
			else if(p1) p2=1;
		printf("%d\n",!p1?0:!p3?1:2);
	}
	return 0;
}