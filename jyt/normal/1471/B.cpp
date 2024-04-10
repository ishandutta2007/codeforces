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
int T,n,m,A[N],B[N],Min,pos;ll ans;
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main()
{
	for(scanf("%d",&T);T--;ans=0)
	{
		scanf("%d%d",&n,&m),Min=1e9;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),ans+=A[i],B[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=A[i];j%m==0;j/=m) B[i]++;
			Min=min(Min,B[i]);
		}
		for(int i=1;i<=n;i++) if(B[i]==Min) {pos=i;break;}
		// dbg1(pos),dbg2(Min);
		for(int i=1;i<pos;i++) ans+=(ll)A[i]*(Min+1);
		for(int i=pos;i<=n;i++) ans+=(ll)A[i]*Min;
		printf("%lld\n",ans);
	}
	return 0;
}