#include <bits/stdc++.h>
using namespace std;
int t;
char s[200005];
int c0,c1;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		c0=c1=0;//
		for(int i=strlen(s)-1;i>=0;--i)
		{
			if(s[i]=='0') ++c0;
			else ++c1; 
		}
		//
		if(c0!=c1) printf("%d\n",min(c0,c1));
		else printf("%d\n",c0-1);
	}
	return 0;
}