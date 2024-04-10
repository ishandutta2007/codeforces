#include<bits/stdc++.h>
using namespace std;
char s[1005];
int n,i,a[2];
int main()
{
	cin>>s;
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')printf("%d 1\n",a[0]*2+1);
		else printf("4 %d\n",3-2*a[1]);
		a[s[i]^'0']^=1;
	}
	return 0;
}