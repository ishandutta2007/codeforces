#include <stdio.h>

long long int s = 0;
int a;
long long int b;

int check[60];
long long int check2[60];
int ans[60];
long long int func2(int k)
{
	if(k==0) return 1;
	if(k==1) return 1;
	if(check2[k]) return check2[k];
	return check2[k] = func2(k-1) + func2(k-2);
	
}
void func(int k, int t)
{
	if(t==0) return;
	if(k>a) return;
	if(check[k]) func(k+1,t);
	else
	{
		check[k] = 1;
		if(s + func2(t-1)>b)
		{
			ans[k] = k;
			func(k+1,t-1);
		}
		else
		{
			s += func2(t-1);
			ans[k] = k+1;
			ans[k+1] = k;
			check[k+1] = 1;
			func(k+2,t-2);
		}
	}
}
int main()
{
	scanf("%d%lld",&a,&b);
	b--;
	
	func(1,a);
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}