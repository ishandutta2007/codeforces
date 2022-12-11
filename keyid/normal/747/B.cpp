#include <bits/stdc++.h>
using namespace std;

const char T[5]={"ACGT"};

int idx(char c)
{
	switch (c)
	{
		case 'A' : return 0;
		case 'C' : return 1;
		case 'G' : return 2;
		case 'T' : return 3;
		default : return 4;
	}
}

int main()
{
	int n,cnt[4]={0};
	char s[260];
	scanf("%d",&n);
	if (n%4)
		printf("===");
	else
	{
		scanf("%s",s);
		for (int i=0;i<n;i++)
			if (s[i]!='?')
				cnt[idx(s[i])]++;
		for (int i=0;i<4;i++)
			if (cnt[i]>n/4)
			{
				printf("===");
				return 0;
			}
		for (int i=0;i<n;i++)
			if (s[i]=='?')
				for (int j=0;j<4;j++)
					if (cnt[j]<n/4)
					{
						s[i]=T[j];
						cnt[j]++;
						break;
					}
		printf("%s",s);
	}
	return 0;
}