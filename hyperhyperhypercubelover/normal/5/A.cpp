#include<cstdio>

char s[222];

int main()
{
	int i,n;
	int now=0,tot=0;
	while(fgets(s,222,stdin))
	{
        if(s[0]=='+')now++;
        else if(s[0]=='-')now--;
		else
		{
			for(n=0;s[n];n++);
            for(i=0;s[i]!=':';i++);
            tot+=now*(n-i-2);
		}
	}
	printf("%d",tot);
}