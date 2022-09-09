#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn=1000006;
const int hst=239017;

long long h[maxn],st[maxn];
int a1[maxn],b1[maxn];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	st[0]=1;
	for (int i=1;i<=n;i++) st[i]=st[i-1]*hst;
	for (int i=1;i<=n;i++) h[i]=0;
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		h[a]=h[a]+b*st[b];
		h[b]=h[b]+a*st[a];
		a1[i]=a;
		b1[i]=b;
	}
	long long kv=1, answer=0;;
	for (int i=0;i<m;i++)
	{
		int a=a1[i];
		int b=b1[i];
		int ha=h[a]-b*st[b];
		int hb=h[b]-a*st[a];
// 		cout << ha << ' ' << hb << endl;
		if (ha==hb) answer++;
	}
	sort(h+1,h+n+1);
	for (int i=2;i<=n;i++)
	{
		if (h[i]==h[i-1]) kv++;
		else
		{
			answer+=kv*(kv-1)/2;
			kv=1;
		}
	}
	answer+=kv*(kv-1)/2;
	cout << answer << endl;
	return 0;
}