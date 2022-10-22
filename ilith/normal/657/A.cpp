#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=400010;
int n,d,h;
signed main(){
	scanf("%d%d%d",&n,&d,&h);
	if(h==n-1){
		if(d==h)FOR(i,2,n)printf("%d %d\n",i-1,i);
		else puts("-1");
		exit(0);
	}
	if(d==h){
		if(d==1)puts("-1"),exit(0);
		FOR(i,1,d)printf("%d %d\n",i+1,i);
		FOR(i,d+1,n-1)printf("%d 2\n",i+1);
		exit(0);
	}
	if(d<h||d>2*h)puts("-1"),exit(0);
	FOR(i,2,h+1)printf("%d %d\n",i-1,i);
	printf("%d %d\n",1,h+2);
	FOR(i,h+3,d+1)printf("%d %d\n",i-1,i);
	FOR(i,d+2,n)printf("%d %d\n",1,i);
	return 0;
}