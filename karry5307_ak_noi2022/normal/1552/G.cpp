//#pragma GCC optimize(2)
#include<cstdio>

using namespace std;

typedef unsigned long long ull;

int I[20][100],c[20];

bool vis_pre[100];int n,k;

bool dfs(int u,ull STA0,ull STA1)
{
	//printf("DFS: %d\n",u);for(int i=0;i<n;i++)printf("%d ",CUR[i]);puts("");
	if(u==k+1)
	{
		for(int i=0;i<n-1;i++)if((STA1&(1ull<<i))&&(STA0&(1ull<<(i+1))))return 0;return 1;
	}
	int cnt0=0,cnt1=0,cntn=0;
	for(int i=0;i<c[u];i++)
	{
		if(STA0&(1ull<<I[u][i]))cnt0++;else if(STA1&(1ull<<I[u][i]))cnt1++;
	}
	cntn=c[u]-cnt0-cnt1;
	for(int i=0;i<c[u];i++)
	{
		if(i<cnt0){if(!(STA0&(1ull<<I[u][i])))STA0^=(1ull<<I[u][i]);if((STA1&(1ull<<I[u][i])))STA1^=(1ull<<I[u][i]);}
		else{if((STA0&(1ull<<I[u][i])))STA0^=(1ull<<I[u][i]);if(!(STA1&(1ull<<I[u][i])))STA1^=(1ull<<I[u][i]);}
	}
	for(int i=0;i<=cntn;i++)
	{
		if(!dfs(u+1,STA0,STA1))return 0;
		if(i<cntn)STA0^=1ull<<I[u][i+cnt0],STA1^=1ull<<I[u][i+cnt0];
	}
	return 1;
}

int main()
{
	//freopen("CF1552G.in","r",stdin);
	scanf("%d%d",&n,&k);if(n==1){puts("ACCEPTED");return 0;}
	
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);for(int j=0;j<c[i];j++){int x=0;scanf("%d",&x);x--;I[i][j]=x;if(i<k)vis_pre[x]=1;}
	}
	bool fl=0;for(int i=0;i<n;i++)if(!vis_pre[i])fl=1;if(fl&&c[k]<n){puts("REJECTED");return 0;}
	
	puts(dfs(1,0,0)?"ACCEPTED":"REJECTED");
}