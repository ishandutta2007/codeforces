#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=400010;
int n,a[N],p,b[N],C,T,x;
signed main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d",&x);
		if(x)a[++C]=x;
	}
	FOR(i,1,n){
		scanf("%d",&x);
		if(x)b[++T]=x;
	}
	FOR(i,T+1,T*2)b[i]=b[i-T];
	if(C!=T)puts("NO"),exit(0);
	FOR(i,1,T)if(b[i]==a[1]){
		p=i;
		break;
	}
	FOR(i,1,T){
		if(b[p-1+i]!=a[i])puts("NO"),exit(0);
	}
	puts("YES");
	return 0;
}