#include <bits/stdc++.h>
using namespace std;

const int MAXL=500005,INF=0x3f3f3f3f;

char s[MAXL],t[MAXL];
int cnt[2],cntt[2],f[MAXL];

void get_fail(char *P,int m)
{
	f[0]=f[1]=0;
	for (int i=1;i<m;i++)
	{
		int j=f[i];
		while (j&&P[i]!=P[j]) j=f[j];
		f[i+1]= P[i]==P[j]?j+1:0;
	}
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	scanf("%s%s",s,t);
	int ls=strlen(s),lt=strlen(t);
	for (int i=0;i<ls;i++)
		cnt[s[i]-'0']++;
	for (int i=0;i<lt;i++)
		cntt[t[i]-'0']++;
	if (cnt[0]>=cntt[0]&&cnt[1]>=cntt[1])
	{
		int now=0;
		for (int i=0;i<lt;i++)
		{
			s[now++]=t[i];
			cnt[t[i]-'0']--;
		}
		get_fail(t,lt);
		int per;
		if (f[lt]==0)
			per=min(cntt[0]?cnt[0]/cntt[0]:INF,cntt[1]?cnt[1]/cntt[1]:INF);
		else
		{
			memset(cntt,0,sizeof(cntt));
			for (int i=f[lt];i<lt;i++)
				cntt[t[i]-'0']++;
			per=min(cntt[0]?cnt[0]/cntt[0]:INF,cntt[1]?cnt[1]/cntt[1]:INF);
		}
		for (int k=0;k<per;k++)
			for (int i=f[lt];i<lt;i++)
			{
				s[now++]=t[i];
				cnt[t[i]-'0']--;
			}
		for (int i=0;i<2;i++)
			for (int j=0;j<cnt[i];j++)
				s[now++]=i+'0';
	}
	puts(s);
	return 0;
}