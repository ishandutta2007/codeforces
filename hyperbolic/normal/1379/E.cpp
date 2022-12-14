#include <stdio.h>

int ans[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a%2==0)
	{
		printf("NO");
		return 0;
	}
	
	if(b==0)
	{
		int k = a+1;
		while(k%2==0) k/=2;
		if(k==1)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("%d ",i/2);
		}
		else printf("NO");
	}
	else if(b==1)
	{
		int k = a+1;
		while(k%2==0) k/=2;
		if(k!=1)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("%d ",i/2);
		}
		else printf("NO");
	}
	else
	{
		int root = 1;
		ans[1] = 0;
		
		for(int i=1;i<=b-1;i++)
		{
			ans[root+1] = root;
			ans[root+2] = root;
			root+=2;
		}
		if((a-root+1)<=3)
		{
			printf("NO");
			return 0;
		}
		//root~a
		int k = (a-root+1)+1;
		while(k%2==0) k/=2;
		if(k!=1)
		{
			for(int i=root+1;i<=a;i++) ans[i] = (i-root+1)/2 + (root-1);
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		}
		else
		{
			if(a==9)
			{
				printf("NO");
				return 0;
			}
			
			ans[a] = 2;
			ans[a-1] = 2;
			a-=2;
			for(int i=root+1;i<=a;i++) ans[i] = (i-root+1)/2 + (root-1);
			printf("YES\n");
			for(int i=1;i<=a+2;i++) printf("%d ",ans[i]);
		}
	}
}