#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=100005;

int a[MAXN],b[MAXN];
map <int,int> ms;

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
		scanf("%d",&b[i]);
	if (a[0]==b[0])
	{
		for (int i=1;i<n;i++)
			ms[a[i]-a[i-1]]++;
		for (int i=1;i<n;i++)
			ms[b[i]-b[i-1]]--;
		for (auto t:ms)
			if (t.second)
			{
				printf("No");
				return 0;
			}
		printf("Yes");
	}
	else
		printf("No");
	return 0;
}