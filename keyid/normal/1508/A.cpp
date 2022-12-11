#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=200005;

char s[3][MAXN];

int get_ch(int l,char *s)
{
	int cnt=0;
	for (int i=0;i<l;i++)
		if (s[i]=='0')
			cnt++;
	return cnt*2>l?0:1;
}

void output(int c,int l,char *s1, char *s2)
{
	int cnt=0;
	for (int i=0;i<l;i++)
	{
		if (s1[i]=='0'+c)
			cnt++;
		if (s2[i]=='0'+c)
			cnt--;
	}
	if (cnt<0)
		swap(s1,s2);
	int head=0;
	for (int i=0;i<l;i++)
	{
		if (s1[i]=='0'+c)
		{
			while (head<l&&s2[head]!='0'+c)
				putchar(s2[head++]);
			head++;
		}
		putchar(s1[i]);
	}
	while (head<l)
		putchar(s2[head++]);
	puts("");
}

void solve()
{
	int n;
	scanf("%d",&n);
	int ty[3];
	for (int i=0;i<3;i++)
	{
		scanf("%s",s[i]);
		ty[i]=get_ch(n*2,s[i]);
	}
	for (int i=0;i<3;i++)
		for (int j=i+1;j<3;j++)
			if (ty[i]==ty[j])
			{
				output(ty[i],n*2,s[i],s[j]);
				return;
			}
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}