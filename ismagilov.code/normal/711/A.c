#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	char arr[1003+1][5];
	int i;
	int j;
	for(i=0;i<n;i++)
	{
	    //for(j=0;j<5;j++)
	    //arr[i][j]=getche();
		scanf("%s",arr[i]);
		//fseek(stdin,0,SEEK_END);
	}
//	char ch=getchar();
/*	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%c",arr[i][j]);
		printf("\n");
	}*/
	for(i=0;i<n;i++)
	{
		if(arr[i][0] == 'O' && arr[i][1]=='O')
		{
			arr[i][0]=arr[i][1]='+';
			break;
		}
		else if(arr[i][3] == 'O' && arr[i][4]=='O')
		{
			arr[i][3]=arr[i][4]='+';
			break;
		}
	}
	if(i==n)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
			printf("%c",arr[i][j]);
			printf("\n");
		}
	}
	return 0;
}