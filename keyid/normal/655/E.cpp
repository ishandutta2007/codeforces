#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005,SIGMA=26,MOD=1000000007;

int cnt[SIGMA],d[SIGMA],q[SIGMA];
char s[MAXN];

bool cmp(int a,int b)
{
	return d[a]<d[b];
}

int main()
{
	int n,k;
	scanf("%d%d%s",&n,&k,s);
	int l=strlen(s),sum=1;
	for (int i=0;i<l;i++)
	{
		int c=s[i]-'a',t=cnt[c];
		cnt[c]=sum;
		sum=(sum+cnt[c]-t)%MOD;
		if (sum<0) sum+=MOD;
		d[c]=i+1;
	}
	for (int i=0;i<k;i++) q[i]=i;
	sort(q,q+k,cmp);
	for (int i=0,now=0;i<n;i++,now=(now+1)%k)
	{
		int c=q[now],t=cnt[c];
		cnt[c]=sum;
		sum=(sum+cnt[c]-t)%MOD;
		if (sum<0) sum+=MOD;
	}
	printf("%d",sum);
	return 0;
}