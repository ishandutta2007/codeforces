#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=100005;

ll ansl[maxn][2],ansr[maxn][2];
int a[maxn];
int n;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d",&a[i]);
	ansl[0][0]=0;
	ansl[0][1]=0;
	for (int i=1;i<n;i++)
	{
		if (a[i]!=1) ansl[i][1]=ansl[i-1][1]+(a[i]-a[i]%2);
		else ansl[i][1]=0;
		if (a[i]%2==1) ansl[i][0]=ansl[i-1][0]+a[i];
		else ansl[i][0]=max(ansl[i-1][1]+a[i],ansl[i-1][0]+a[i]-1);
	}
// 	for (int i=0;i<n;i++) cout << ansl[i][0] << ' ' << ansl[i][1] << endl;
	ansr[n-1][0]=0;
	ansr[n-1][1]=0;
	for (int i=n-2;i>=0;i--)
	{
		if (a[i+1]!=1) ansr[i][1]=ansr[i+1][1]+(a[i+1]-a[i+1]%2);
		else ansr[i][1]=0;
		if (a[i+1]%2==1) ansr[i][0]=ansr[i+1][0]+a[i+1];
		else ansr[i][0]=max(ansr[i+1][1]+a[i+1],ansr[i+1][0]+a[i+1]-1);
	}
	ll answer=0;
	for (int i=0;i<n;i++) answer=max(answer,max(ansl[i][1]+ansr[i][0],ansl[i][0]+ansr[i][1]));
	cout << answer << endl;
	return 0;
}