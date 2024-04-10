#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

typedef long long LL;
typedef pair <int,int> pii;

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int b,k;
	scanf("%d%d",&b,&k);
	int now=0;
	for (int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		now=(now*b+a)%2;
	}
	printf(now?"odd":"even");
	return 0;
}