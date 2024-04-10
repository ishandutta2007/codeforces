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
int T,n,a,cnt0,cnt1;
int main()
{
	for(scanf("%d",&T);T--;cnt0=cnt1=0)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a),a&1?cnt1++:cnt0++;
		puts(cnt0^cnt1?"No":"Yes");
	}
	return 0;
}