#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=3005;

int a[MAXN],num[MAXN];
LL f[MAXN],mins[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		a[i]-=i;
		num[i]=a[i];
	}
	sort(num,num+n);
	int nc=unique(num,num+n)-num;
	for (int i=0;i<nc;i++) f[i]=abs(a[0]-num[i]);
	mins[0]=f[0];
	for (int i=1;i<nc;i++) mins[i]=min(mins[i-1],f[i]);
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<nc;j++) f[j]=abs(a[i]-num[j])+mins[j];
		mins[0]=f[0];
		for (int j=1;j<nc;j++) mins[j]=min(mins[j-1],f[j]);
	}
	printf("%lld",mins[nc-1]);
	return 0;
}