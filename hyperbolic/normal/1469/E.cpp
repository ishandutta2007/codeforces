#include <stdio.h>
#include <vector>
#include <set>
#define MOD 99999971

int a,b;
std::vector<int> temp;
std::set<long long int> S;

int func(int k,long long int sum)
{
	if(k>b)
	{
		if(S.find(sum)!=S.end()) return 0;
		else return 1;
	}
	
	temp.push_back(0);
	int c = func(k+1,MOD*sum+'0');
	if(c==1) return 1;
	temp.pop_back();
	
	temp.push_back(1);
	c = func(k+1,MOD*sum+'1');
	if(c==1) return 1;
	temp.pop_back();
	
	return 0;
}

char x[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		temp.clear();
		
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		
		long long int sum = 0;
		for(int i=1;i<=b;i++)
		{
			sum *= MOD;
			sum += ('0'+'1'-x[i]);
		}
		S.insert(sum);
		
		long long int C = 1;
		for(int i=1;i<b;i++) C *= MOD;
		for(int i=b+1;i<=a;i++)
		{
			sum -= C*('0'+'1'-x[i-b]);
			sum *= MOD;
			sum += ('0'+'1'-x[i]);
			S.insert(sum);
		}
		
		int k = func(1,0);
		if(k==0) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=0;i<temp.size();i++) printf("%d",temp[i]);
			printf("\n");
		}
	}
}