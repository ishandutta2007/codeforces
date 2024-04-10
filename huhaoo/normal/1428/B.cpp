#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int x; scanf("%d",&x); return x;
}
const int N=300010;
int main()
{
	fr(T,1,read())
	{
		static char s[N];
		int n=read();
		scanf("%s",s+1);
		int f1=1,f2=1;
		fr(i,1,n)
		{
			if(s[i]=='>') f1=0;
			if(s[i]=='<') f2=0;
		}
		if(f1||f2){ printf("%d\n",n); continue; }
		int ans=0;
		s[0]=s[n]; s[n+1]=s[1];
		fr(i,1,n) if(s[i-1]=='-'||s[i]=='-') ans++;
		printf("%d\n",ans);
	}
	return 0;
}