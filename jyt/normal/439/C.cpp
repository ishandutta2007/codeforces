#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,K,A[N],cnt,cnt0,cnt1,mark[N];
int main()
{
	scanf("%d%d%d",&n,&m,&K),m=m-K;
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),A[i]&1?cnt1++:cnt0++;
	if((cnt1&1)!=(m&1)||cnt1<m) return puts("NO"),0;
	if((cnt1-m)/2+cnt0<K) return puts("NO"),0;
	puts("YES");
	if(!K)
	{
		for(int i=1;i<=n;i++)
			if((A[i]&1)&&m>1) mark[i]=1,m--,printf("1 %d\n",A[i]);
		for(int i=1;i<=n;i++) if(!mark[i]) cnt++;
		printf("%d",cnt);
		for(int i=1;i<=n;i++) if(!mark[i]) printf(" %d",A[i]);
		return 0;
	}
	for(int i=1;i<=n;i++)
		if((A[i]&1)&&m) mark[i]=1,m--,printf("1 %d\n",A[i]);
		else if(!(A[i]&1)&&K>1) mark[i]=1,K--,printf("1 %d\n",A[i]);
	for(int i=1;i<=n;i++)
		if(!mark[i]&&K>1)
		{
			if(!cnt) printf("2 %d",A[i]),cnt=1;
			else printf(" %d\n",A[i]),cnt=0,K--;
			mark[i]=1;
		}
	for(int i=1;i<=n;i++) if(!mark[i]) cnt++;
	printf("%d",cnt);
	for(int i=1;i<=n;i++) if(!mark[i]) printf(" %d",A[i]);
	return 0;
}