#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
typedef long long ll;
long long ans,a[N<<1];
int n;
char s[N<<1];

int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)s[i+n]=s[i];
	for (int i=0;i<n*2;i++)
	{
		if (i==0 || s[i]==s[i-1])	a[i]=1;
		else a[i]=min((ll)n,a[i-1]+1);
	}
	for (int i=0;i<n*2;i++)ans=max(ans,a[i]);
	printf("%lld\n",ans);
	return 0;
}