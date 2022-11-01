#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m;

void solve()
{
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		puts("0");
		return;
	}
	printf("%d\n",min(2,min(n,m)));
}
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve(); 
	}
	return 0;
}