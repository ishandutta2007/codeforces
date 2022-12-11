#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int b,g,n,ans=0;
	scanf("%d%d%d",&b,&g,&n);
	for (int i=0;i<=b;i++)
		if (n-i>=0&&n-i<=g)
			ans++;
	printf("%d",ans);
	return 0;
}