#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=100005;

int b[MAXN];

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
		scanf("%d",&b[i]);
	int ans=b[n-1]-b[0]+1;
	for (int i=n-1;i>=1;i--)
		b[i]=b[i]-b[i-1]-1;
	k--;
	nth_element(b+1,b+k,b+n,greater<int>());
	for (int i=1;i<=k;i++)
		ans-=b[i];
	printf("%d",ans);
	return 0;
}