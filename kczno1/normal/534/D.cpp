#include<bits/stdc++.h>

const int N=200000;
int t[N],next[N+2];

int n,i,x,ans[N],top;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i) 
	{
		scanf("%d",&x);
		next[i]=t[x];t[x]=i;
	}
	for(i=0;;++i)
	{
		while(i>=3&&!t[i]) i-=3;
		if(!t[i]) break;
	    ans[++top]=t[i];t[i]=next[t[i]];
	}
	if(top<n) { puts("Impossible");return 0; }
	puts("Possible");
	for(i=1;i<=n;++i) printf("%d ",ans[i]);
}