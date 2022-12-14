#include <stdio.h>
#include <vector>
#define MAX 1234567890

int a;
std::vector<int> V;
long long int check[90][170][1000];
int sum[110];
long long int func(int s, int t, int k)
{
	if(k<0) return MAX;
	
	//printf("%d %d %d %lld!!\n",s,t,k,check[s][t+a][k]);
	if(s==V.size())
	{
		if(t!=0) return MAX;
		if(k!=0) return MAX;
		return 0;
	}
	if(check[s][t+a][k]!=-1) return check[s][t+a][k];
	
	int d = V[s] + t;
	long long int ans = MAX;
	if(d<0)
	{
		for(int i=0;i<=d+sum[s+1];i++)
		{
			long long int S = func(s+1,d-i,k-(i-d)) + i*(i-1)/2;
			ans = ans<S?ans:S;
		}
	}
	else
	{
		for(int i=0;i<=d;i++)
		{
			long long int S = func(s+1,d-i,k-(d-i)) + i*(i-1)/2;
			ans = ans<S?ans:S;
		}
		for(int i=d+1;i<=d+sum[s+1];i++)
		{
			long long int S = func(s+1,d-i,k-(i-d)) + i*(i-1)/2;
			ans = ans<S?ans:S;
		}
	}
	return check[s][t+a][k] = ans;
}

int x[110];
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int s = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==1)
		{
			V.push_back(s);
			s = 0;
		}
		else s++;
	}
	V.push_back(s);
	
	sum[V.size()] = 0;
	for(int i=V.size()-1;i>=0;i--) sum[i] = sum[i+1] + V[i];
	
	int k = (a+1)/2;
	
	long long int S = 0;
	for(int i=0;i<V.size();i++) S += V[i];
	long long int p = S*(S-1)/2;
	long long int ans = 0;
	
	for(int i=0;i<=V.size();i++) for(int j=0;j<=2*a;j++) for(int l=0;l<=p;l++) check[i][j][l] = -1;
	for(int i=0;i<=k*(k-1)/2;i++)
	{
		long long int t = func(0,0,i);
		ans = ans>p-t?ans:p-t;
		printf("%lld ",ans);
	}
	//printf("!\n");
	for(int i=k*(k-1)/2+1;i<=a*(a-1)/2;i++) printf("%lld " ,ans);
}