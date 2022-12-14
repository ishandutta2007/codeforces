#include <stdio.h>
#include <map>
int x[110];
std::map<int,int> check,M;
int C = 0;
int func(int k)
{
	if(k==1) return 0;
	if(check.find(k)!=check.end()) return check[k];
	C++;
	int check2[32]={};
	for(int i=1;i<=31;i++)
	{
		int t = ((k>>i)|(k&((1<<i)-1)));
		if(t==k) continue;
		check2[func(t)] = 1;
	}
	for(int i=0;i<=31;i++) if(check2[i]==0) return check[k] = i;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	long long int ans = 0;
	for(int i=2;i*i<=1000000000;i++)
	{
		int state = 1;
		for(int j=1;j<=a;j++)
		{
			int count = 0;
			while(x[j]%i==0) count++,x[j]/=i;
			state = (state|(1<<count));
		}
		ans^=func(state);
	}
	for(int i=1;i<=a;i++) if(x[i]>1) M[x[i]]++;
	int t = M.size();
	for(int i=1;i<=t;i++) ans^=1;
	if(C>5000)
	{
		printf("%d!!",C);
		return 0;
	}
	if(ans==0) printf("Arpa");
	else printf("Mojtaba");
}