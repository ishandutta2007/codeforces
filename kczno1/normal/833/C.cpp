#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
int L[20],R[20];
int c[10],ans,n;

bool check(int _u)
{
	static int c[10];
	memcpy(c,::c,sizeof(c));
	int u=_u;
	if(u&(1<<R[n])-(1<<L[n]+1))return 1;
	int i=n;
	for(;i>=0;--i)
	{
		--c[R[i]];
		if(c[R[i]]<0)break;
		if(i==0)return 1;
		if(c[R[i]]==0)u^=1<<R[i];
		if(u&((1<<R[i-1])-1))return 1;
	}
	
	memcpy(c,::c,sizeof(c));
	u=_u;
	i=n;
	for(;i>=0;--i)
	{
		--c[L[i]];
		if(c[L[i]]<0)break;
		if(i==0)return 1;
		if(c[L[i]]==0)u^=1<<L[i];
		if(u>>L[i-1]+1)return 1;
	}
	
	return 0;
}
void dfs(int x,int leave,int u)
{
	if(x==10)
	{
		c[0]=leave;
	/*	if(c[5]&&leave)
			int yyx=1;
			
		if(check(u|bool(leave)))
		{
			rep(i,1,9)
			rep(j,1,c[i])printf("%d",i);
			puts("");
		}*/
		ans+=check(u|bool(leave));
		return ;
	}
	rep(i,0,leave)
	{
		c[x]=i;
		dfs(x+1,leave-i,u|(bool(i)<<x));
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	static char sL[20],sR[20];
	scanf("%s%s",sL,sR);
	rep(i,0,strlen(sL)-1)L[strlen(sL)-1-i]=sL[i]-'0';
	rep(i,0,strlen(sR)-1)R[strlen(sR)-1-i]=sR[i]-'0';
	int i=18;
	while(i&&L[i]==R[i])--i;
	if(L[i]==R[i]){puts("1");exit(0);}
	n=i;
	dfs(1,n+1,0);
	cout<<ans;
}