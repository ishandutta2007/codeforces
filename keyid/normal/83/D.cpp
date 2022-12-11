#include <cstdio>
#include <cmath>

int a,b,ans,pc,prime[25000];
bool vis[50000];

bool is_prime(int k)
{
	int m=sqrt(k+0.5);
	for (int i=2;i<=m;i++) if (!(k%i)) return false;
	return true;
}

void make_prime(int k)
{
	int m=sqrt(k+0.5);
	for (int i=2;i<=m;i++)
		if (!vis[i])
			for (int j=i*i;j<k;j+=i) vis[j]=true;
	for (int i=2;i<k;i++) if (!vis[i]) prime[pc++]=i;
}

void dfs(int cur,int x,int c)
{
	ans+=c*(b/x-(a-1)/x);
	for (int i=cur;i<pc;i++)
		if (prime[i]<=b/x) dfs(i+1,x*prime[i],-c);
}

int main()
{
	int k;
	scanf("%d%d%d",&a,&b,&k);
	if (is_prime(k))
	{
		if ((long long)k*k>b) printf("%d",a<=k&&b>=k?1:0);
		else
		{
			make_prime(k);
			dfs(0,k,1);
			printf("%d",ans);
		}
	}
	else printf("0");
	return 0;
}