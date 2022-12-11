#include <cstdio>
#include <cstring>

const int MAXL=100005;

char s[2][MAXL],ans[MAXL];

int main()
{
	scanf("%s%s",s[0],s[1]);
	int l=strlen(s[0]),now=0,cnt=0;
	for (int i=0;i<l;i++)
		if (s[0][i]==s[1][i]) ans[i]=s[0][i];
		else
		{
			ans[i]=s[now][i];
			now^=1;
			cnt++;
		}
	if (cnt&1) printf("impossible");
	else printf("%s",ans);
	return 0;
}