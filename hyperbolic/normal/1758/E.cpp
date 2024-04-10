#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}


std::vector< std::vector<int> > V,check;
std::vector< std::vector< std::pair< int,int > > > W1,W2;
int control,a,b,c;
void func(int s, int t, int val)
{
	if(control) return;
	if(V[s][t]!=-1 && V[s][t]!=val)
	{
		control = 1;
		return;
	}
	if(check[s][t]!=0) return;
	check[s][t] = 1;
	V[s][t] = val;
	for(int j=0;j<W1[t].size();j++)
	{
		int val2 = ((val+W1[t][j].second)%c+c)%c;
		func(s,W1[t][j].first,val2);
	}
	for(int i=0;i<W2[s].size();i++)
	{
		int val2 = ((val+W2[s][i].second)%c+c)%c;
		func(W2[s][i].first,t,val2);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		check.clear();
		W1.clear();
		W2.clear();
		control = 0;
		
		scanf("%d%d%d",&a,&b,&c);
		
		V.resize(a+2);
		for(int i=0;i<=a+1;i++) V[i].resize(b+2);
		check.resize(a+2);
		for(int i=0;i<=a+1;i++) check[i].resize(b+2);
		W1.resize(b+2);
		W2.resize(a+2);
		
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&V[i][j]);
		
		for(int i=1;i<=a;i++)
		{
			std::vector<int> save;
			for(int j=1;j<=b;j++) if(V[i][j]!=-1) save.push_back(j);
			for(int j=0;j+1<save.size();j++) W1[save[j]].push_back(std::make_pair(save[j+1],V[i][save[j+1]]-V[i][save[j]]));
			std::reverse(save.begin(),save.end());
			for(int j=0;j+1<save.size();j++) W1[save[j]].push_back(std::make_pair(save[j+1],V[i][save[j+1]]-V[i][save[j]]));
		}
		for(int j=1;j<=b;j++)
		{
			std::vector<int> save;
			for(int i=1;i<=a;i++) if(V[i][j]!=-1) save.push_back(i);
			for(int i=0;i+1<save.size();i++) W2[save[i]].push_back(std::make_pair(save[i+1],V[save[i+1]][j]-V[save[i]][j]));
			std::reverse(save.begin(),save.end());
			for(int i=0;i+1<save.size();i++) W2[save[i]].push_back(std::make_pair(save[i+1],V[save[i+1]][j]-V[save[i]][j]));
		}
		
		int C = 0, C2 = 0, C3 = 0;
		long long int ans = 1;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(V[i][j]!=-1 && check[i][j]==0)
				{
					func(i,j,V[i][j]);
					C++;
					if(control)
					{
						printf("0\n");
						goto u;
					}
				}
			}
		}
		for(int i=1;i<=b;i++)
		{
			int val = 1;
			for(int j=1;j<=a;j++) if(V[j][i]!=-1) val = 0;
			C2 += val;
		}
		for(int i=1;i<=a;i++)
		{
			int val = 1;
			for(int j=1;j<=b;j++) if(V[i][j]!=-1) val = 0;
			C3 += val;
		}
		
		if(C2<=C3)
		{
			ans *= power(c,C2), ans %= MOD;
			C += C2, C3 -= C2;
			ans *= power(c,C-1), ans %= MOD;
			ans *= power(c,C3), ans %= MOD;
		}
		else
		{
			ans *= power(c,C3), ans %= MOD;
			C += C3, C2 -= C3;
			ans *= power(c,C-1), ans %= MOD;
			ans *= power(c,C2), ans %= MOD;
		}
		printf("%lld\n",ans);
		u:;
	}
}