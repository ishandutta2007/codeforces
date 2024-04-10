#include <bits/stdc++.h>
using namespace std;

char s[30],a[2][15];
int app[30];

int main()
{
	scanf("%s",s+1);
	int l,r;
	for (int i=1;i<=27;i++)
		if (app[s[i]-'A'])
		{
			l=app[s[i]-'A'];
			r=i;
			break;
		}
		else
			app[s[i]-'A']=i;
	int d=r-l-1;
	if (d==0) printf("Impossible");
	else
	{
		int k=d/2;
		a[0][k]=s[l];
		for (int i=k-1;i>=0;i--)
			a[0][i]=s[l+(k-i)];
		k=d-k;
		for (int i=0;i<k;i++)
			a[1][i]=s[l+(d-k)+1+i];
		int now=r+1;
		for (int i=d-k+1;i<13&&now<=27;i++,now++)
			a[0][i]=s[now];
		if (now<=27)
		{
			for (int i=12;now<=27;i--,now++)
				a[1][i]=s[now];
			now=l-1;
			for (int i=k;now>=1;i++,now--)
				a[1][i]=s[now];
		}
		else
		{
			now=l-1;
			for (int i=k;i<13;i++,now--)
				a[1][i]=s[now];
			for (int i=12;now>=1;i--,now--)
				a[0][i]=s[now];
		}
		for (int i=0;i<2;i++) printf("%s\n",a[i]);
	}
	return 0;
}