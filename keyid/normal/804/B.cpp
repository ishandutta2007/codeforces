#include <bits/stdc++.h>
using namespace std;

const int MAXL=1000005,MOD=1000000007;

int p2[MAXL];
char s[MAXL];

int main()
{
	scanf("%s",s);
	int l=strlen(s),ans=0,cnta=0;
	p2[0]=1;
	for (int i=1;i<=l;i++)
		p2[i]=p2[i-1]*2%MOD;
	for (int i=0;i<l;i++)
		if (s[i]=='b')
			ans=(ans+p2[cnta]-1)%MOD;
		else
			cnta++;
	printf("%d",ans);
	return 0;
}