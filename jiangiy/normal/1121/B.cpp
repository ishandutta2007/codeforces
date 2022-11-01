#include<bits/stdc++.h>

int s[1010],c[233333];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	for(int i=1;i<=n;i++)for(int j=1;j<i;j++)c[s[i]+s[j]]++;
	int t=0;
	for(int i=1;i<233333;i++)t=std::max(t,c[i]);
	printf("%d",t);
}