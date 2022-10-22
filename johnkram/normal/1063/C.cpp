#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid,i;
bool c;
char s[10];
int main()
{
	scanf("%d",&n);
	puts("1 0");
	fflush(stdout);
	scanf("%s",s);
	c=s[0]=='b';
	for(i=n-2,l=0;~i;i--)
	{
		printf("1 %d\n",r=l+(1<<i));
		fflush(stdout);
		scanf("%s",s);
		if((s[0]=='b')^c)break;
		else l=r;
	}
	if(~i)
	{
		for(i--;~i;i--)
		{
			mid=l+r>>1;
			printf("1 %d\n",mid);
			fflush(stdout);
			scanf("%s",s);
			if((s[0]=='b')^c)r=mid;
			else l=mid;
		}
		printf("0 %d 2 %d\n",l,r);
	}
	else printf("0 %d 2 %d\n",l+1,l+1);
	fflush(stdout);
	return 0;
}