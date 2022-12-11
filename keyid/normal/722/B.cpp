#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;

int p[MAXN];
char s[MAXN];

bool check(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&p[i]);
	gets(s);
	for (int i=0;i<n;i++)
	{
		gets(s);
		int l=strlen(s),cnt=0;
		for (int j=0;j<l;j++)
			if (check(s[j]))
				cnt++;
		if (cnt!=p[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}