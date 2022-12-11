#include <bits/stdc++.h>
using namespace std;

const int MAXL=100005;

char s[MAXL];
int cnt[200];

int main()
{
	scanf("%s",s);
	int l=strlen(s);
	for (int i=0;i<l;i++)
		cnt[s[i]]++;
	int ans=min(cnt['B'],cnt['b']);
	ans=min(ans,cnt['u']/2);
	ans=min(ans,cnt['a']/2);
	ans=min(ans,cnt['l']);
	ans=min(ans,cnt['s']);
	ans=min(ans,cnt['r']);
	printf("%d",ans);
	return 0;
}