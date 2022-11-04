#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

//#define O4 __inline__ __attribute__((always_inline))
//O4 char nc(){
//	static char buf[100000],*p1=buf,*p2=buf;
//	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//O4 int read(){
//	char t;int u=0,k=1;t=getchar();
//	while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
//	while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
//	return u*k;
//} 

const int MAXSIZE = 1 << 18 | 1;
char buf[MAXSIZE], *p1, *p2;

inline int Gc() {
	return p1 == p2 &&
		(p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
}
template<typename T> inline void read(T& x) {
	x = 0; int f = 0, ch = Gc();
	while (!isdigit(ch)) f |= ch == '-', ch = Gc();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
	if (f) x = -x;
}
inline void write(register int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10^48);
}


const int N=4010,inf=1e9;
int f[N][N];
int prefc[N][N];
int cost[N][N];
int n,k;
 
vector<int>dp,newdp;
 
// l,r = what I want to solve for newdp, optl,optr = bounds in dp
void solvedp(int l,int r,int optl,int optr){
	if(l>r)return;
	int m=(l+r)/2;
	pair<int,int>bst={inf,0};
	for(int i=optl;i<=min(m,optr);++i){
		bst=min(bst,{cost[m][i]+dp[i-1],i});
	}
	newdp[m]=bst.first;
	solvedp(l,m-1,optl,bst.second);
	solvedp(m+1,r,bst.second,optr);
}
 
main(){
	read(n);read(k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			read(f[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=i;j>=1;--j)
			prefc[i][j]=f[i][j]+prefc[i][j+1];
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			cost[j][i]=cost[j-1][i]+prefc[j][i];
	dp.resize(n+1,inf);
	newdp.resize(n+1);
	dp[0]=0;
	for(int i=0;i<k;++i){
		solvedp(1,n,1,n);
		swap(dp,newdp);
	}
	write(dp[n]);
}