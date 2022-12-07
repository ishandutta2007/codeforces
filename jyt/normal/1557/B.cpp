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
int T,n,m,A[N],id[N],val;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m),val=n;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),id[i]=i;
		std::sort(id+1,id+1+n,[](int t1,int t2){return A[t1]<A[t2];});
		for(int i=1;i<n;i++) if(id[i]+1==id[i+1]) val--;
		// dbg2(val);
		puts(val>m?"No":"Yes");
	}
	return 0;
}