#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=1005;

int p[MAXN];
double h[MAXN];

int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	for (int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for (int i=0;i<n;i++)
		h[i]=r;
	for (int i=1;i<n;i++)
		for (int j=0;j<i;j++)
		{
			int dx=abs(p[i]-p[j]);
			if (dx<=r*2)
				h[i]=max(h[i],h[j]+sqrt(4*r*r-dx*dx));
		}
	for (int i=0;i<n;i++)
		printf("%.8f\n",h[i]);
	return 0;
}