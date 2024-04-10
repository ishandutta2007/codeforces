#include <cstdio>
#include <iostream>

using namespace std;

const int inf=1e9;
const int maxn=20005;

int t[maxn];
int sum[maxn];

int main()
{
	int n;
	scanf("%d",&n);
// 	for (int n=3;n<=20000;n++)
// 	{
	for (int i=0;i<n;i++) scanf("%d",&t[i]);/*t[i]=1;*/
	int maxsum=-inf;
	for (int i=3;i<=n;i++) if (n%i==0)
	{
		int l=n/i;
		for (int j=0;j<l;j++) sum[j]=0;
		for (int j=0;j<n;j++) sum[j%l]+=t[j];
		for (int j=0;j<l;j++) if (sum[j]>maxsum) maxsum=sum[j];
	}
	cout << maxsum << endl;
// 	cerr << n << endl;
// 	}
	return 0;
}