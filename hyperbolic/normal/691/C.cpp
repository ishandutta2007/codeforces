#include <stdio.h>
#include <string.h>
char x[1000010];
int main()
{
	int a,c,start,end;
	scanf("%s",x+1);
	a = strlen(x+1);
	c = a+1;
	start = 0;
	end = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='.')
		{
			c = i;
			break;
		}
	}
	for(int i=1;i<c;i++)
	{
		if(x[i]!='0')
		{
			start = i;
			break;
		}
	}
	for(int i=a;i>c;i--)
	{
		if(x[i]!='0')
		{
			end = i;
			break;
		}
	}
	if(start==0)
	{
		if(end==0)
		{
			printf("0");
			return 0;
		}
		else
		{
			int k;
			for(k=c+1;k<=end;k++)
			{
				if(x[k]!='0')
				{
					if(k==end) printf("%c",x[k]);
					else
					{
						printf("%c.",x[k]);
						for(int i=k+1;i<=end;i++) printf("%c",x[i]);
					}
					printf("E%d",c-k);
					return 0;
				}
			}
		}
	}
	else
	{
		if(end==0)
		{
			int k;
			for(k=c-1;k>=start;k--)
			{
				if(x[k]!='0')
				{
					if(k==start) printf("%c",x[k]);
					else
					{
						printf("%c.",x[start]);
						for(int i=start+1;i<=k;i++) printf("%c",x[i]);
					}
					if(start==c-1) return 0;
					else
					{
						printf("E%d",c-start-1);
						return 0;
					}
				}
			}
		}
		else
		{
			printf("%c.",x[start]);
			for(int i=start+1;i<c;i++) printf("%c",x[i]);
			for(int i=c+1;i<=end;i++) printf("%c",x[i]);
			if(start==c-1) return 0;
			else
			{
				printf("E%d",c-start-1);
				return 0;
			}
		}
	}
}