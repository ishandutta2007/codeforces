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

const int maxn=200005;

int a[maxn],b[maxn];
int n;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	int cur=0;
	for (int i=0;i<n;i++)
	{
		while (cur<n && b[cur]!=a[i]) cur++;
		if (cur==n)
		{
			cout << n-i << endl;
			return 0;
		}
		cur++;
	}
	cout << 0 << endl;
	return 0;
}