#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

typedef long long LL;

const int MAX=2000005;

bool vis[MAX];
int pc,prime[MAX],sum[MAX],sum2[MAX];

void preprocess()
{
	for (int i=2;i<=2000000;i++)
	{
		if (!vis[i])
		{
			prime[pc++]=i;
			sum[i]=1;
		}
		for (int j=0;j<pc;j++)
		{
			int t=prime[j]*i;
			if (t>2000000) break;
			vis[t]=true;
			if (i%prime[j]==0) break;
		}
	}
	char t[10];
	for (int i=1;i<=2000000;i++)
	{
		sum[i]+=sum[i-1];
		sprintf(t,"%d",i);
		string num1=t,num2=t;
		reverse(num1.begin(),num1.end());
		sum2[i]=sum2[i-1]+(num1==num2);
	}
}

int main()
{
	preprocess();
	int p,q;
	scanf("%d%d",&p,&q);
	for (int i=2000000;i>=1;i--)
		if ((LL)sum[i]*q<=(LL)p*sum2[i])
		{
			printf("%d",i);
			return 0;
		}
	printf("Palindromic tree is better than splay tree");
	return 0;
}