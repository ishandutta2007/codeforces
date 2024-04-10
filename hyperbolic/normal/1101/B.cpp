#include <stdio.h>
#include <string.h>

char x[500010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int left = -1, right = -1;
	int state;
	state = 1;
	for(int i=1;i<=a;i++)
	{
		if(state==1&&x[i]=='[') state++;
		else if(state==2&&x[i]==':')
		{
			left = i;
			break;
		}
	}
	state = 1;
	for(int i=a;i>=1;i--)
	{
		if(state==1&&x[i]==']') state++;
		else if(state==2&&x[i]==':')
		{
			right = i;
			break;
		}
	}
	if(left==-1||right==-1) printf("-1");
	else if(left>=right) printf("-1");
	else
	{
		int count = 0;
		for(int i=left;i<=right;i++) if(x[i]=='|') count++;
		printf("%d",count+4);
	}
}