#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

char s[100005];

int ans[100005][256];
int ncan[255][255];

int main()
{
	int k;
	scanf("%s",s+1);
	s[0]=' ';
// 	printf("%s",s);
	scanf("%d\n",&k);
	memset(ncan,0,sizeof(ncan));
	for (int i=0;i<k;i++)
	{
		char c1,c2;
		scanf("%c%c\n",&c1,&c2);
		ncan[c1][c2]=1;
		ncan[c2][c1]=1;
// 		cout << c1 << c2 << endl;
	}
	int n=strlen(s);
	memset(ans,0,sizeof(ans));
	for (int i=1;i<n;i++)
	{
		for (char ch='a';ch<='z';ch++)
		{
			ans[i][ch]=ans[i-1][ch]+1;
		}
// 		cout << s[i] << endl;
		for (char ch='a';ch<='z';ch++)
		{
			if (ncan[ch][s[i]]==0)
			{
// 				cout << "try " << i << ch << s[i] << endl;
				ans[i][s[i]]=min(ans[i][s[i]],ans[i-1][ch]);
			}
		}
	}
	int answer=1000000000;
	for (char ch='a';ch<='z';ch++) answer=min(answer,ans[n-1][ch]);
	cout << answer << endl;
	return 0;
}