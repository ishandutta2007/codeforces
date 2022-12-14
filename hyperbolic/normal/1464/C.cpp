#include <stdio.h>

int func(char k)
{
	int t = k-'a';
	return (1<<t);
}

char x[100010];
int count[110];
int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=a-2;i++) count[x[i]-'a']++;
	b -= func(x[a]);
	b += func(x[a-1]);
	if(b<0) b = (-b);
	
	long long int sum = 0;
	for(int i=1;i<=a-2;i++) sum += func(x[i]);
	if(b>sum) printf("No");
	else if((sum-b)%2==1) printf("No");
	else
	{
		long long int S = (sum-b)/2;
		for(int i=0;;i++)
		{
			if(S==0) break;
			if(S%2==1)
			{
				if(count[i]==0)
				{
					printf("No");
					return 0;
				}
				else count[i]--;
			}
			count[i+1] += (count[i]/2);
			S/=2;
		}
		printf("Yes");
	}
}