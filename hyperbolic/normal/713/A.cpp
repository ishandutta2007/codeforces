#include <stdio.h>
#include <map>
#include <string.h>
#include <vector>

std::vector<int> V;
char x[1010],y[1010];
std::map<long long int,int> count;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		scanf("%s",x+1);
		if(x[1]=='+')
		{
			long long int a;
			scanf("%lld",&a);
			
			while(a)
			{
				V.push_back((a%10)%2);
				a/=10;
			}
			while(V.size()<18) V.push_back(0);
			V.push_back(1);
			
			long long int s = 0;
			for(int i=0;i<V.size();i++) s*=2, s+=V[i];
			count[s]++;
		}
		else if(x[1]=='-')
		{
			long long int a;
			scanf("%lld",&a);
			
			while(a)
			{
				V.push_back((a%10)%2);
				a/=10;
			}
			while(V.size()<18) V.push_back(0);
			V.push_back(1);
			
			long long int s = 0;
			for(int i=0;i<V.size();i++) s*=2, s+=V[i];
			count[s]--;
		}
		else
		{
			scanf("%s",y+1);
			int b = strlen(y+1);
			for(int i=b;i>=1;i--) V.push_back(y[i]-'0');
			while(V.size()<18) V.push_back(0);
			V.push_back(1);
			
			long long int s = 0;
			for(int i=0;i<V.size();i++) s*=2, s+=V[i];
			
			printf("%lld\n",count[s]);
		}
	}
}