#include<cstdio>

char s[222222];
int t[33];

int main()
{
	int i,n,r=0;
	scanf("%d%s",&n,s);
    for(i=0;i<n-1;i++)
	{
        t[s[i*2]-'a']++;
		if(t[s[i*2+1]-'A'])t[s[i*2+1]-'A']--;
		else r++;
	}
	printf("%d",r);
}