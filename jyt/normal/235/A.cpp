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
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n;
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main()
{
	scanf("%d",&n);
	if(n<3)  return !printf("%d\n",n);
	if(n&1) return !printf("%lld\n",1ll*n*(n-1)*(n-2));
	if(gcd(n,n-3)>1) printf("%lld\n",1ll*(n-1)*(n-2)*(n-3));
	else printf("%lld\n",1ll*n*(n-1)*(n-3));
	return 0;
}