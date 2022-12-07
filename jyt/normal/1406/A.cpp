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
#define N 105
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],cnt[N],Max,flag,ans;
void clear()
{
	flag=Max=ans=0;
	for(int i=1;i<=n;i++) cnt[A[i]]--;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),cnt[A[i]]++,Max=max(Max,A[i]);
		for(int i=0;i<=Max+1;i++)
		{
			if(cnt[i]>1) continue;
			if(!cnt[i])
			{
				if(flag) ans+=i;
				else ans+=i+i;
				break;
			}
			if(cnt[i]==1&&!flag) ans+=i,flag=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}