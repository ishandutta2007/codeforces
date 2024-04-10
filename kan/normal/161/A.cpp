#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn=2e5+5;

int ans[maxn],a[maxn],b[maxn];
int n,m,x,y;

int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	int cur=0;
	memset(ans,0,sizeof(ans));
	int answer=0;
	for (int i=0;i<m;i++)
	{
		while (cur<n && a[cur]+y<b[i]) cur++;
		if (cur>=n || a[cur]-x>b[i]) continue;
		ans[cur+1]=i+1;
		answer++;
		cur++;
// 		cout << cur+1 << ' ' << i+1 << endl;
	}
	printf("%d\n",answer);
	for (int i=1;i<=n;i++) if (ans[i]!=0) printf("%d %d\n",i,ans[i]);
	return 0;
}