#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair <int,int> pii;

const int MAXL=1000005;

char a[MAXL],b[MAXL];

int main()
{
	//freopen("read.txt","r",stdin);
	int n;
	scanf("%d%s%s",&n,a,b);
	int c1=0,c2=0;
	for (int i=0;i<n;i++)
		if (a[i]!=b[i])
			c1++;
	for (int i=0;i+1<n;i++)
		if (a[i]!=b[i]&&a[i]==b[i+1]&&a[i+1]==b[i])
		{
			c2++;
			i++;
		}
	printf("%d",c1-c2);
	return 0;
}