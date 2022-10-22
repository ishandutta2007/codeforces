#include<bits/stdc++.h>
using namespace std;
int n,i,s[100];
char c[100005];
int main()
{
	scanf("%d%s",&n,c);
	for(i=0;i<n;i++)s[c[i]-'a']++;
	if(n==1)
	{
		puts("Yes");
		return 0;
	}
	for(i=0;i<26;i++)if(s[i]>1)break;
	if(i==26)puts("No");
	else puts("Yes");
	return 0;
}