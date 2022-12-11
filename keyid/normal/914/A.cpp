#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

const int MAXN=1005;

int a[MAXN];

bool check(int x)
{
	int m=sqrt(x);
	for (int i=m-3;i<=m+3;i++)
		if (i*i==x)
			return false;
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for (int i=n-1;i>=0;i--)
		if (a[i]<0||check(a[i]))
		{
			printf("%d",a[i]);
			break;
		}
	return 0;
}