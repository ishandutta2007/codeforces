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
	int n,d,e;
	scanf("%d%d%d",&n,&d,&e);
	e*=5;
	int ans=n;
	for (int i=0;i*d<=n;i++)
		ans=min(ans,(n-i*d)%e);
	printf("%d",ans);
	return 0;
}