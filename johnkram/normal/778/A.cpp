#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n,m,i,j,a[MAXN],l,r,mid,y[MAXN][26];
char s[MAXN],t[MAXN],x[MAXN];
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	l=0;
	r=n-m+1;
	while(l+1<r)
	{
		mid=l+r>>1;
		copy(s+1,s+n+1,x+1);
		for(i=1;i<=mid;i++)x[a[i]]=0;
		for(i=n-1;~i;i--)
		{
			copy(y[i+1],y[i+1]+26,y[i]);
			if(x[i+1])y[i][x[i+1]-'a']=i+1;
		}
		for(i=1,j=0;i<=m;i++)if(y[j][t[i]-'a'])j=y[j][t[i]-'a'];
		else break;
		if(i>m)l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}