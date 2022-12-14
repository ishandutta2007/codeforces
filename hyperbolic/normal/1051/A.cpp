#include <stdio.h>
#include <string.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		int control1 = 0, control2 = 0, control3 = 0;
		for(int i=1;i<=a;i++) if('0'<=x[i]&&x[i]<='9') control1++;
		for(int i=1;i<=a;i++) if('a'<=x[i]&&x[i]<='z') control2++;
		for(int i=1;i<=a;i++) if('A'<=x[i]&&x[i]<='Z') control3++;
		if(control1*control2*control3!=0) for(int i=1;i<=a;i++) printf("%c",x[i]);
		else if(control1==0&&control2==0)
		{
			x[1] = '0', x[2] = 'a';
			for(int i=1;i<=a;i++) printf("%c",x[i]);
		}
		else if(control2==0&&control3==0)
		{
			x[1] = 'a', x[2] = 'A';
			for(int i=1;i<=a;i++) printf("%c",x[i]);
		}
		else if(control1==0&&control3==0)
		{
			x[1] = '0', x[2] = 'A';
			for(int i=1;i<=a;i++) printf("%c",x[i]);
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				char temp = x[i];
				for(char j='0';j<='9';j++)
				{
					x[i] = j;
					int C1 = 0, C2 = 0, C3 = 0;
					for(int k=1;k<=a;k++) if('0'<=x[k]&&x[k]<='9') C1++;
					for(int k=1;k<=a;k++) if('a'<=x[k]&&x[k]<='z') C2++;
					for(int k=1;k<=a;k++) if('A'<=x[k]&&x[k]<='Z') C3++;
					if(C1*C2*C3>0)
					{
						for(int k=1;k<=a;k++) printf("%c",x[k]);
						goto u;
					}
					x[i] = temp;
				}
				for(char j='a';j<='z';j++)
				{
					x[i] = j;
					int C1 = 0, C2 = 0, C3 = 0;
					for(int k=1;k<=a;k++) if('0'<=x[k]&&x[k]<='9') C1++;
					for(int k=1;k<=a;k++) if('a'<=x[k]&&x[k]<='z') C2++;
					for(int k=1;k<=a;k++) if('A'<=x[k]&&x[k]<='Z') C3++;
					if(C1*C2*C3>0)
					{
						for(int k=1;k<=a;k++) printf("%c",x[k]);
						goto u;
					}
					x[i] = temp;
				}
				for(char j='A';j<='Z';j++)
				{
					x[i] = j;
					int C1 = 0, C2 = 0, C3 = 0;
					for(int k=1;k<=a;k++) if('0'<=x[k]&&x[k]<='9') C1++;
					for(int k=1;k<=a;k++) if('a'<=x[k]&&x[k]<='z') C2++;
					for(int k=1;k<=a;k++) if('A'<=x[k]&&x[k]<='Z') C3++;
					if(C1*C2*C3>0)
					{
						for(int k=1;k<=a;k++) printf("%c",x[k]);
						goto u;
					}
					x[i] = temp;
				}
			}
			u:;
		}
		printf("\n");
	}
}