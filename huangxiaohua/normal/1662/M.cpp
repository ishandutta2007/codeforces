#include<bits/stdc++.h>
#define x first
#define y second
#define rnd (rand()<<15|rand())
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define ROF(a,b,c) for(int a=(b),a##_end=(c);a>=a##_end;--a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f,N=1e6+10,P=998244353;
template<class T>inline bool chkmin(T &x,const T &y){return y<x?x=y,1:0;}
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
int n;
int main(){
	int cas;
	scanf("%d",&cas);
	while(cas--){
		int m;
		scanf("%d%d",&n,&m);
		int Mx1=0,Mx2=0;
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			chkmax(Mx1,x);
			chkmax(Mx2,y);
		}
		if(Mx1+Mx2>n)
			puts("IMPOSSIBLE");
		else{
			FOR(i,1,Mx1)putchar('R');
			FOR(i,1,n-Mx1)putchar('W');
			putchar('\n');
		}
	}
	return 0;
}