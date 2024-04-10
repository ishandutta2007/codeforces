#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXTIME=86400;
const int maxn=4005;

int ans[MAXTIME+5][2];
int t[maxn],d[maxn];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&t[i],&d[i]);
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=n;i++)
	{
// 		ans[time][0]=0;
		for (int time=MAXTIME;time>t[i];time--)
		{
			ans[time][1]=ans[time][0]+1;
			if (t[i]+d[i]<=time) ans[time][1]=min(ans[time][1],ans[time-d[i]][0]);
// 			if (time==40001 || time==20001)
// 			{
// 				cout << time << ' ' << i << ' ' << ans[time][1] << endl;
// 			}
			ans[time][0]=ans[time][1];
		}
	}
	int cur=0;
	int sleep;
	int maxans=0;
// 	cout << ans[40001][1] << endl;
	for (int time=1;time<=MAXTIME;time++) if (ans[time][1]<=k)
	{
		while (cur<n && t[cur+1]<time) 
		{
// 			cout << cur << ' ' << n << ' ' << t[cur+1] << ' ' << time << endl;
			cur++;
		}
		int can=k-ans[time][1];
		if (cur+1+can>n) sleep=MAXTIME+1;
		else sleep=t[cur+1+can];
// 		if (time==40001) cout << cur << ' ' << t[cur+1] << ' ' << sleep << endl;
		maxans=max(maxans,sleep-time);
	}
	cout << maxans << endl;
	return 0;
}