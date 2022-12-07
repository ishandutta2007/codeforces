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
#define N 300005
#define mod 998244353
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,A[N],fac[N],inv[N],ans;
int cal(int x) {x-=x<mod?0:mod;return x;}
int C(int x,int y) {return x<0||y<0||x<y?0:(ll)fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main()
{
	scanf("%d",&n),n<<=1,fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=2;i<=n;i++) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++) inv[i]=(ll)inv[i-1]*inv[i]%mod;
	std::sort(A+1,A+1+n);
	for(int i=1;i<=n;i++) ans=i>n/2?cal(ans+A[i]%mod):cal(ans-A[i]%mod+mod);
	ans=2ll*ans*C(n-1,n/2-1)%mod;
	printf("%d\n",ans);
	return 0;
}