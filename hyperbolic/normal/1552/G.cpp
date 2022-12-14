#include <stdio.h>
#include <vector>
#include <map>
int check[110][110],a,b;
std::vector<int> S[110],T1[110],T2[110],V[110];
//std::map<long long int,bool> M[110];
bool func(int k, long long int bit)
{
	//if(M[k].find(bit)!=M[k].end()) return M[k][bit];
	
	if(k>b)
	{
		for(int i=1;i<a;i++)
		{
			int s1 = (bit>>i)%2;
			int s2 = (bit>>(i+1))%2;
			if(s1>s2) return 0;
		}
		return 1;
	}
	
	long long int bit2 = bit;
	int count = 0;
	for(int i=0;i<T1[k].size();i++)
	{
		if((bit>>T1[k][i])%2==1)
		{
			bit2 ^= (1LL<<T1[k][i]);
			count++;
		}
	}
	
	int limit = V[k].size()-1;
	for(int i=limit;i>=limit-count+1;i--) bit2 ^= (1LL<<V[k][i]);
	
	int t = func(k+1,bit2);
	if(t==0) return 0;
	
	int C = T2[k].size();
	for(int i=limit-count;C--;i--)
	{
		bit2 ^= (1LL<<V[k][i]);
		t = func(k+1,bit2);
		if(t==0) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d",&a,&b);
	if(a==1)
	{
		printf("ACCEPTED");
		return 0;
	}
	
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
		{
			int d;
			scanf("%d",&d);
			V[i].push_back(d);
		}
	}
	
	for(int i=1;i<=b;i++) for(int j=0;j<V[i].size();j++) for(int k=i;k<=b;k++) check[k][V[i][j]] = 1;
	
	for(int i=1;i<=b;i++) for(int j=1;j<=a;j++) if(check[i][j]==1) S[i].push_back(j);
	for(int i=1;i<=b;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			if(check[i-1][V[i][j]]==1) T1[i].push_back(V[i][j]);
			else T2[i].push_back(V[i][j]);
		}
	}
	
	for(int j=1;j<=a;j++)
	{
		if(check[b][j]==0)
		{
			printf("REJECTED");
			return 0;
		}
	}
	
	int t = func(1,0);
	if(t==1) printf("ACCEPTED");
	else printf("REJECTED");
}