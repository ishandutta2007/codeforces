#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	for(int i=1;i<=b;i++) ans*=a, ans%=MOD;
	return ans;
}

int count[10];
std::vector<int> V;
char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='A') count[1]++;
		if(x[i]=='C') count[2]++;
		if(x[i]=='G') count[3]++;
		if(x[i]=='T') count[4]++;
	}
	for(int i=1;i<=4;i++) V.push_back(count[i]);
	std::sort(V.begin(),V.end());
	if(V[0]==V[1]&&V[1]==V[2]&&V[2]==V[3]) printf("%lld",power(4,a));
	else if(V[1]==V[2]&&V[2]==V[3]) printf("%lld",power(3,a));
	else if(V[2]==V[3]) printf("%lld",power(2,a));
	else printf("1");
}